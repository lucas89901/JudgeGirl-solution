from __future__ import annotations

import datetime
import http.client
import mimetypes
import os
import pathlib
import re
import urllib.parse

import flask
import werkzeug.utils

STATIC_FOLDER_PATTERN = re.compile(r'judgegirl.csie.org(?P<time>_\d+_\d+)?')


def discover_static_folder() -> pathlib.Path | None:
    newest_folder = None
    for folder in pathlib.Path().iterdir():
        if not folder.is_dir():
            continue
        match = STATIC_FOLDER_PATTERN.fullmatch(folder.name)
        if not match:
            continue

        clone_time = None
        if match.group('time'):
            try:
                clone_time = datetime.datetime.strptime(
                    match.group('time').strip('_'), '%Y%m%d_%H%M%S')
            except ValueError:
                pass
        if clone_time is None:
            # Assume time of clone is the creation time of folder.
            clone_time = datetime.datetime.fromtimestamp(
                os.path.getctime(folder))

        if newest_folder is None or clone_time > newest_folder[1]:
            newest_folder = (folder, clone_time)

    if newest_folder is None:
        return None
    return newest_folder[0]


app = flask.Flask(__name__, static_folder=discover_static_folder())


def file_path_for_url(url: str,
                      POST_data: dict[str, str] | str | None = None) -> str:
    """Returns the local file path of the resource specified by `url`.

    The path points to where wget saves the file under recursive mode and
    with "restrict_file_names" set to "unix". If POST data exists, it is
    appended as a custom component preceded by an exclamation mark (!).
    """
    parsed = urllib.parse.urlparse(url)
    path = f'{parsed.netloc}{parsed.path}'
    if parsed.query:
        # Remove escape sequences to match the default filenames produced by
        # wget.
        query = urllib.parse.unquote(parsed.query)
        # Wget escapes '/' on Unix-like operating systems.
        query = query.replace('/', '%2F')
        path += f'?{query}'
    if POST_data:
        if isinstance(POST_data, str):
            # Assume that POST_data is already percent-encoded.
            path += f'!{POST_data}'
        else:
            path += f'!{urllib.parse.urlencode(POST_data)}'
    return path


def make_response_from_file(path) -> flask.Response | None:
    try:
        app.logger.debug('Trying to send file: %s', path)
        with open(werkzeug.utils.safe_join(app.static_folder, path), 'rb') as f:
            # Extract original headers stored at the beginning of file.
            original_headers = {}
            first_line = f.readline()
            if first_line.startswith(b'HTTP'):
                original_headers = http.client.parse_headers(f)
            else:
                app.logger.warning('Reading file without original headers.')
                f.seek(0)

            # Make sure to call f.read() only after headers have been parsed,
            # otherwise the headers would be included in the response body.
            response = flask.make_response(f.read())
            if 'Content-Type' in original_headers:
                response.content_type = original_headers['Content-Type']
            else:
                mimetype, _ = mimetypes.guess_type(path)
                if mimetype:
                    response.content_type = mimetype
                else:
                    response.content_type = 'application/octet-stream'
                app.logger.warning(
                    'Content-Type not found in original headers. Guessing from '
                    'path and falling back to application/octet-stream if type '
                    'cannot be guessed.')
            for k, v in original_headers.items():
                if 'Cookie' not in k:  # Strip Cookie-related headers
                    response.headers.add(f'Original-{k}', v)
        app.logger.debug('File found')
        return response
    except FileNotFoundError:
        app.logger.debug('File not found')


@app.route('/<path:path>', methods=['GET', 'POST'])
def all_routes(path: str):
    # Use flask.request.full_path because it includes query string. Remove the
    # first '/', otherwise werkzeug.utils.safe_join() would return None.
    local_path = file_path_for_url(flask.request.full_path,
                                   flask.request.form).lstrip('/')
    response = make_response_from_file(local_path)
    if response:
        return response

    # Fall back to file path without any query string or form data.
    response = make_response_from_file(path)
    if response:
        return response

    flask.abort(404)


if __name__ == '__main__':
    app.run(debug=True)

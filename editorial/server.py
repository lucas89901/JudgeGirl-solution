import os
import pathlib
import sys

import flask
import github
import livereload

github_api = github.Github(auth=github.Auth.Token(os.getenv('GH_TOKEN')))
REPOSITORY = github_api.get_repo('gpwaob92679/JudgeGirl-solution')

app = flask.Flask(__name__,
                  static_folder=pathlib.Path(sys.argv[1]).resolve().parent,
                  static_url_path='/')


@app.route('/')
def root():
    with open(sys.argv[1], 'r', encoding='utf-8') as f:
        body = github_api.render_markdown(f.read(), context=REPOSITORY)
    return flask.render_template('editorial.html', body=body)


if __name__ == '__main__':
    server = livereload.Server(app.wsgi_app)
    server.watch(sys.argv[1])
    server.serve()

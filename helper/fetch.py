import argparse
import os
import pathlib
import shutil

import bs4
import requests

DOMAIN_ID_TO_TITLE = {
    0: 'The C Programming',
    1: 'Parallel Programming',
    2: 'Data Structures and Algorithms',
    3: 'Lab332 Training',
}


class FetchError(Exception):
    """Failed to fetch problem from JudgeGirl."""


def main():
    parser = argparse.ArgumentParser(
        description='Fetch problem metadata from JudgeGirl and generate '
        'solution file from template.')
    parser.add_argument('domain', type=int, help='Domain ID.')
    parser.add_argument('id', type=int, help='Problem ID.')
    args = parser.parse_args()

    os.chdir('..')

    response = requests.get(
        f'https://judgegirl.csie.org/problem/{args.domain}/{args.id}',
        allow_redirects=False)
    if response.status_code != 200:
        raise FetchError(
            'Failed to fetch problem from JudgeGirl. Perhaps the problem does '
            'not exist or the server is currently down.')
    soup = bs4.BeautifulSoup(response.text, 'html.parser')
    title = soup.find('h1').text

    solution_file = pathlib.Path(f'{DOMAIN_ID_TO_TITLE[args.domain]}/{title}.c')
    if solution_file.exists():
        raise FileExistsError(f'Solution file already exists: {solution_file}')
    shutil.copyfile('template.c', solution_file)


if __name__ == '__main__':
    main()

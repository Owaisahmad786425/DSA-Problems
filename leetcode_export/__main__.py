import argparse
import logging
import os
from string import Template
from typing import Optional

from leetcode_export._version import __version__
from leetcode_export.leetcode import LeetCode
from leetcode_export.utils import VALID_PROGRAMMING_LANGUAGES


def parse_args():
    parser = argparse.ArgumentParser(description="Export LeetCode submissions")

    parser.add_argument("--cookies", type=str, help="LeetCode cookies")
    parser.add_argument("--folder", type=str, default=".", help="Output folder")

    parser.add_argument(
        "--submission-filename",
        type=str,
        default="${date_formatted} - ${status_display} - runtime ${runtime} - memory ${memory}.${extension}",
        help="Submission filename format",
    )
    parser.add_argument("--only-accepted", action="store_true", help="Only accepted")
    parser.add_argument("--only-last-submission", action="store_true", help="Only last")
    parser.add_argument(
        "--language",
        dest="language_unprocessed",
        type=str,
        help="Comma-separated language list (e.g. python,cpp,java)",
    )
    parser.add_argument("--no-problem-statement", action="store_true", help="Skip statement")
    parser.add_argument(
        "--problem-statement-filename",
        type=str,
        default="${question_id}-${title_slug}.md",
        help="Problem statement filename",
    )
    parser.add_argument(
        "--problem-statement-content",
        type=str,
        default="<h1>${question_id} - ${title}</h1><h2>Difficulty: ${difficulty} - <a href=\"https://leetcode.com/problems/${title_slug}/\">${title_slug}</a></h2>${content}",
        help="Problem statement content format",
    )
    parser.set_defaults(verbose=False, extra_verbose=False)
    parser.add_argument("-v", "--verbose", action="store_true", help="Verbose")
    parser.add_argument("-vv", "--extra-verbose", action="store_true", help="Extra verbose")
    parser.add_argument("-V", "--version", action="version", version=__version__)
    
    args = parser.parse_args()

    if args.language_unprocessed:
        languages = args.language_unprocessed.split(",")
        args.language = [lang.strip() for lang in languages]
        for lang in args.language:
            if lang not in VALID_PROGRAMMING_LANGUAGES:
                parser.error(f"Invalid language: {lang}")
    else:
        args.language = None

    return args


def configure_logging(args):
    logging.basicConfig(
        level=logging.DEBUG,
        format="%(asctime)s [%(levelname)s] %(filename)s:%(lineno)d - %(message)s",
        handlers=[
            logging.FileHandler("debug.log", encoding="UTF8"),
            logging.StreamHandler()
        ]
    )
    if args.extra_verbose:
        logging.getLogger().setLevel(logging.DEBUG)
    elif args.verbose:
        logging.getLogger().setLevel(logging.INFO)
    else:
        logging.getLogger().setLevel(logging.WARNING)


def main():
    args = parse_args()
    configure_logging(args)

    logging.info("Running LeetCode Export")

    leetcode = LeetCode()
    cookies = args.cookies or input("Insert LeetCode cookies: ")

    if not leetcode.set_cookies(cookies):
        logging.error("Invalid cookies.")
        exit(1)

    if not os.path.exists(args.folder):
        os.mkdir(args.folder)
    os.chdir(args.folder)

    title_slug_to_exported_languages = {}
    last_submission_timestamp: Optional[int] = None

    print("Exporting LeetCode submissions...")

    for submission in leetcode.get_submissions():
        if (
            last_submission_timestamp is not None and
            submission.timestamp > last_submission_timestamp
        ):
            logging.warning("Submissions not in reverse order.")
        last_submission_timestamp = submission.timestamp

        if args.only_accepted and submission.status_display != "Accepted":
            continue

        if args.language and submission.lang not in args.language:
            continue

        if submission.title_slug not in title_slug_to_exported_languages:
            title_slug_to_exported_languages[submission.title_slug] = set()

        if (
            args.only_last_submission and
            submission.lang in title_slug_to_exported_languages[submission.title_slug]
        ):
            continue

        title_slug_to_exported_languages[submission.title_slug].add(submission.lang)

        # Get problem statement
        problem = leetcode.get_problem_statement(submission.title_slug)

        # Fallback for topic_tags if missing
        topic_tags = getattr(problem, "topicTags", [])
        if not topic_tags:
            topic_tags = [{"name": "Misc"}]

        for tag in topic_tags:
            topic_dir = tag["name"].replace(" ", "_")
            full_dir = os.path.join(args.folder, topic_dir, submission.title_slug)
            os.makedirs(full_dir, exist_ok=True)

            # Save problem statement
            if not args.no_problem_statement:
                statement_file = Template(args.problem_statement_filename).substitute(**problem.__dict__)
                statement_path = os.path.join(full_dir, statement_file)
                if not os.path.exists(statement_path):
                    with open(statement_path, "w", encoding="utf-8") as f:
                        content = Template(args.problem_statement_content).substitute(**problem.__dict__)
                        f.write(content)

            # Save submission
            filename = Template(args.submission_filename).substitute(**submission.__dict__)
            filepath = os.path.join(full_dir, filename)
            if not os.path.exists(filepath):
                with open(filepath, "w", encoding="utf-8") as f:
                    f.write(submission.code)

    print("✅ All submissions exported successfully!")


if __name__ == "__main__":
    main()

import os
import re
import shutil
import requests
from bs4 import BeautifulSoup
from time import sleep

BASE_DIR = r"C:\Users\HP\leetcode-export"  # <- yahan apna folder path daal

def extract_slug(folder_name):
    match = re.match(r"\d+-(.*)", folder_name)
    return match.group(1) if match else folder_name

def get_tags_from_leetcode(slug):
    url = f"https://leetcode.com/problems/{slug}/"
    headers = {'User-Agent': 'Mozilla/5.0'}
    res = requests.get(url, headers=headers)

    if res.status_code != 200:
        print(f"⚠️ Failed to fetch: {slug}")
        return []

    soup = BeautifulSoup(res.text, "html.parser")
    tag_div = soup.find("div", string=lambda t: t and "Related Topics" in t)

    tags = []
    if tag_div:
        links = tag_div.find_next("div").find_all("a")
        tags = [link.text.strip() for link in links]

    # fallback for new layout
    if not tags:
        try:
            tags = [tag.text for tag in soup.select('[data-track-load="related-topic"] a')]
        except:
            pass

    return tags

def main():
    folders = [f for f in os.listdir(BASE_DIR) if os.path.isdir(os.path.join(BASE_DIR, f))]

    for folder in folders:
        slug = extract_slug(folder)
        print(f"🔍 Getting tags for: {slug}")
        tags = get_tags_from_leetcode(slug)

        if not tags:
            print(f"❌ No tags found for: {slug}")
            continue

        for tag in tags:
            topic_folder = os.path.join(BASE_DIR, tag)
            os.makedirs(topic_folder, exist_ok=True)

            src_path = os.path.join(BASE_DIR, folder)
            dst_path = os.path.join(topic_folder, folder)

            shutil.copytree(src_path, dst_path, dirs_exist_ok=True)
            print(f"✅ Copied {folder} → {tag}")

        sleep(0.3)  # avoid getting blocked

if __name__ == "__main__":
    main()

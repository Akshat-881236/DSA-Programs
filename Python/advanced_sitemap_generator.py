import time
import json
import requests
from datetime import datetime
from lxml import etree
from openai import OpenAI

# ===================== CONFIG =====================
GOOGLE_API_KEY = "AIzaSyC8fxmK7l5_cHEJOI5vZvtA0-HcejyIqgU"
GOOGLE_CX = "5600b150cfc154fbf"

# 🔴 OpenAI API key directly inside code
OPENAI_API_KEY = "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"

GOOGLE_SEARCH_URL = "https://www.googleapis.com/customsearch/v1"
MAX_PAGES = 10          # 10 pages × 10 results = 100 URLs max
OUTPUT_FILE = "sitemap.xml"
# =================================================

client = OpenAI(api_key=OPENAI_API_KEY)


# ---------- STEP 1: Discover URLs from Google ----------
def discover_urls(domain_prefix):
    urls = set()
    start = 1

    for _ in range(MAX_PAGES):
        params = {
            "key": GOOGLE_API_KEY,
            "cx": GOOGLE_CX,
            "q": f"site:{domain_prefix}",
            "start": start
        }

        response = requests.get(GOOGLE_SEARCH_URL, params=params)
        data = response.json()

        if "items" not in data:
            break

        for item in data["items"]:
            urls.add(item["link"])

        start += 10
        time.sleep(1)

    return list(urls)


# ---------- STEP 2: Clean URLs using OpenAI ----------
def clean_urls_with_ai(urls):
    prompt = f"""
You are an SEO expert.

Clean this list for sitemap.xml:
- Remove duplicates
- Remove query strings (?utm, ?ref, etc.)
- Remove fragments (#)
- Remove admin, login, auth, dashboard pages
- Normalize trailing slashes
- Keep only canonical URLs

Return ONLY a valid JSON array.

URLs:
{json.dumps(urls, indent=2)}
"""

    response = client.chat.completions.create(
        model="gpt-4o-mini",
        messages=[{"role": "user", "content": prompt}],
        temperature=0
    )

    return json.loads(response.choices[0].message.content)


# ---------- STEP 3: Generate Sitemap XML ----------
def generate_sitemap(urls):
    urlset = etree.Element(
        "urlset",
        xmlns="http://www.sitemaps.org/schemas/sitemap/0.9"
    )

    for url in urls:
        url_el = etree.SubElement(urlset, "url")
        etree.SubElement(url_el, "loc").text = url
        etree.SubElement(url_el, "lastmod").text = datetime.utcnow().strftime("%Y-%m-%d")
        etree.SubElement(url_el, "changefreq").text = "weekly"
        etree.SubElement(url_el, "priority").text = "0.8"

    tree = etree.ElementTree(urlset)
    tree.write(
        OUTPUT_FILE,
        pretty_print=True,
        xml_declaration=True,
        encoding="UTF-8"
    )


# ---------- MAIN ----------
def main():
    domain = input("Enter domain prefix (example: akshat-881236.github.io): ").strip()

    print("\n🔍 Discovering URLs from Google...")
    raw_urls = discover_urls(domain)
    print(f"Found {len(raw_urls)} raw URLs")

    if not raw_urls:
        print("❌ No URLs found. Check domain or Google API setup.")
        return

    print("\n🧠 Cleaning URLs using OpenAI...")
    clean_urls = clean_urls_with_ai(raw_urls)
    print(f"Final sitemap URLs: {len(clean_urls)}")

    print("\n📄 Generating sitemap.xml...")
    generate_sitemap(clean_urls)

    print("\n✅ sitemap.xml created successfully!")


if __name__ == "__main__":
    main()
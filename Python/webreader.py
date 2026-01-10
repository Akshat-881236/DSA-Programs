import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse
from textblob import TextBlob
# Note: TextBlob is a simple NLP library used here for quick summary generation.
# For production-level summarization, you would use models from libraries like NLTK or Hugging Face Transformers.

def generate_summary(text, sentences=3):
    """
    Generates a simple summary of the text using TextBlob's sentence extraction.
    This method is very basic and is primarily for demonstration.
    """
    try:
        blob = TextBlob(text)
        # Select the first 'sentences' number of sentences for a simple summary
        summary = " ".join([str(s).strip() for s in blob.sentences[:sentences]])
        return summary
    except Exception as e:
        return f"Could not generate summary: {e}"

def read_website(url):
    print(f"\n🔍 Reading: {url}")

    try:
        # 1. Fetch the content
        response = requests.get(url, timeout=10, headers={
            "User-Agent": "MiniAI-Crawler/1.0"
        })
        response.raise_for_status()
    except Exception as e:
        print(f"❌ Failed to fetch page: {e}")
        return

    # 2. Parse the HTML
    soup = BeautifulSoup(response.text, "lxml")

    # ---- BASIC INFO ----
    title = soup.title.string.strip() if soup.title else "No title"
    desc_tag = soup.find("meta", attrs={"name": "description"})
    description = desc_tag["content"].strip() if desc_tag else "No description"

    # ---- CLEAN TEXT EXTRACTION (FOR SUMMARY) ----
    # 3. Remove script and style elements to clean the text
    for script_or_style in soup(["script", "style"]):
        script_or_style.decompose()

    # 4. Get all visible text and clean up whitespace
    content_text = soup.get_text(separator=' ', strip=True)

    # ---- LINKS ----
    base_domain = urlparse(url).netloc
    internal_links = set()
    external_links = set()

    for a in soup.find_all("a", href=True):
        full_url = urljoin(url, a["href"])
        parsed = urlparse(full_url)

        if parsed.scheme.startswith("http"):
            # Check if the domain matches the base domain
            if parsed.netloc == base_domain:
                internal_links.add(full_url)
            else:
                external_links.add(full_url)

    # 5. Generate the summary
    summary = generate_summary(content_text, sentences=3)
    
    # ---- Console Output ----
    print(f"📌 Title: {title}")
    print(f"📝 Description: {description}")
    print(f"🔗 Internal links: {len(internal_links)} : {list(internal_links)}")
    print(f"🌐 External links: {len(external_links)} : {list(external_links)}")
    print(f"💡 Generated Summary: {summary[:400]}...") # Print a snippet

    return {
        "url": url,
        "title": title,
        "description": description,
        "internal_links": list(internal_links),
        "external_links": list(external_links),
        "summary": summary # NEW FIELD
    }

# -------- RUNTIME ENTRY --------
if __name__ == "__main__":
    print("Enter website URLs (comma separated):")
    # Example input for testing: https://www.python.org, https://docs.python.org/3/
    user_input = input("> ")

    urls = [u.strip() for u in user_input.split(",") if u.strip()]

    results = []
    for url in urls:
        data = read_website(url)
        if data:
            results.append(data)
    
    
    
    print("\n✅ Finished reading all websites.")
    print("\n" + "="*50)
    print("      FINAL REPORT: WEBSITE ANALYTICS")
    print("="*50)

    for result in results:
        print(f"\n### 📄 Summary for {result['url']} ###")
        print(f"* **Title:** {result['title']}")
        print(f"* **Description:** {result['description']}")
        print(f"* **Internal Links:** {len(result['internal_links'])} links found")
        print(f"* **External Links:** {len(result['external_links'])} links found")
        print("\n> **GENERATED SUMMARY:**")
        print(f"> {result['summary']}")
        print("\n" + "-"*40)
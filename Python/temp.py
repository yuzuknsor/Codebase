import jieba
import requests
from bs4 import BeautifulSoup

# Define the headers for the HTTP request
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36 Edg/125.0.0.0"
}

# Define the base URL
base_url = "https://www.biqugen.net/book/36454/14212082.html"
with open("121.txt", "a+", encoding="utf-8") as f:
    f.truncate(0)
jieba.setLogLevel(jieba.logging.INFO)
for i in range(50):
    response = requests.get(base_url, headers = headers)

    html = response.text.replace('<br>','')
    soup = BeautifulSoup(html, "html.parser")
    link = soup.find("a", attrs={"id": "link-next"})
    logs = soup.find("div", attrs = {"id": "content"})
    with open("121.txt", "a", encoding="utf-8") as f:
        for log in logs:
            f.write(log.text)
    base_url = link.get("href")
txt = open("121.txt", "r", encoding = "utf-8").read()
words = jieba.lcut(txt)
counts = {}
for word in words:
    if len(word) == 1:
        continue
    else:
        counts[word] = counts.get(word,0) + 1
items = list(counts.items())
items.sort(key=lambda x:x[1], reverse=True)
for i in range(100):
    word, count = items[i]
    print("{0:<10}{1:>5}".format(word, count))
import http.server
import socketserver
import urllib.parse
import os
from datetime import datetime

PORT = 8888
DATA_FILE = "comments.txt"

def load_comments():
    if not os.path.exists(DATA_FILE):
        return []
    with open(DATA_FILE, "r", encoding="utf-8") as f:
        lines = [line.strip() for line in f if line.strip() and not line.startswith("#")]
    return [line.split("|", 4) for line in lines]

def save_comment(user, article_id, content):
    comments = load_comments()
    cid = len(comments) + 1
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(DATA_FILE, "a", encoding="utf-8") as f:
        f.write(f"{cid}|{user}|{article_id}|{now}|{content}\n")

class CommentHandler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        if self.path == "/submit":
            length = int(self.headers['Content-Length'])
            data = self.rfile.read(length).decode("utf-8")
            parsed = urllib.parse.parse_qs(data)
            user = parsed.get("user", ["匿名"])[0].replace("|", "")
            article_id = parsed.get("article_id", ["1"])[0].replace("|", "")
            content = parsed.get("content", [""])[0].replace("|", "")
            if content.strip():
                save_comment(user.strip(), article_id.strip(), content.strip())
            self.send_response(303)
            self.send_header("Location", "/")
            self.end_headers()

    def do_GET(self):
        if self.path == "/" or self.path == "/index.html":
            with open("index.html", "r", encoding="utf-8") as f:
                template = f.read()
            comments = load_comments()
            html = ""
            for cid, user, article_id, time, content in reversed(comments[-10:]):
                html += f"<div class='comment'><b>{user}</b> 在 <b>文章{article_id}</b> 评论于 {time}<br>{content}</div>\n"
            page = template.replace("<!--COMMENTS-->", html)
            self.send_response(200)
            self.send_header("Content-type", "text/html; charset=utf-8")
            self.end_headers()
            self.wfile.write(page.encode("utf-8"))
        else:
            super().do_GET()

with socketserver.TCPServer(("", PORT), CommentHandler) as httpd:
    print(f"Serving at http://localhost:{PORT}")
    httpd.serve_forever()

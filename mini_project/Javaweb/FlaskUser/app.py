from flask import Flask, render_template, request, redirect, url_for, session, flash
from werkzeug.security import generate_password_hash, check_password_hash
from werkzeug.utils import secure_filename
import os, sqlite3, time


app = Flask(__name__)
app.secret_key = 'secret_key'
app.config['UPLOAD_FOLDER'] = os.path.join('static', 'uploads')
ALLOWED_EXTENSIONS = {'png', 'jpg', 'jpeg', 'gif'}

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

def get_db():
    conn = sqlite3.connect('app.db')
    conn.row_factory = sqlite3.Row
    return conn

@app.route('/')
def index():
    return redirect(url_for('login'))

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        file = request.files['avatar']
        conn = get_db()
        cur = conn.cursor()
        cur.execute('SELECT id FROM users WHERE username=?', (username,))
        if cur.fetchone():
            flash('用户名已存在')
            return redirect(url_for('register'))
        password_hash = generate_password_hash(password)
        cur.execute('INSERT INTO users (username, password_hash) VALUES (?, ?)', (username, password_hash))
        user_id = cur.lastrowid
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            ext = filename.rsplit('.', 1)[1].lower()
            new_filename = f"{int(time.time())}.{ext}"
            user_folder = os.path.join(app.config['UPLOAD_FOLDER'], username)
            os.makedirs(user_folder, exist_ok=True)
            file_path = os.path.join(user_folder, new_filename)
            file.save(file_path)
            cur.execute('INSERT INTO avatars (user_id, filename, upload_time) VALUES (?, ?, ?)',
                        (user_id, new_filename, time.strftime('%Y-%m-%d %H:%M:%S')))
        conn.commit()
        conn.close()
        flash('注册成功，请登录')
        return redirect(url_for('login'))
    return render_template('register.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        conn = get_db()
        cur = conn.cursor()
        cur.execute('SELECT id, password_hash FROM users WHERE username=?', (username,))
        user = cur.fetchone()
        conn.close()
        if user and check_password_hash(user['password_hash'], password):
            session['user_id'] = user['id']
            session['username'] = username
            return redirect(url_for('profile'))
        flash('用户名或密码错误')
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.clear()
    return redirect(url_for('login'))

@app.route('/profile', methods=['GET', 'POST'])
def profile():
    if 'user_id' not in session:
        return redirect(url_for('login'))
    conn = get_db()
    cur = conn.cursor()
    username = session['username']
    user_id = session['user_id']
    if request.method == 'POST':
        file = request.files['avatar']
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            ext = filename.rsplit('.', 1)[1].lower()
            new_filename = f"{int(time.time())}.{ext}"
            user_folder = os.path.join(app.config['UPLOAD_FOLDER'], username)
            os.makedirs(user_folder, exist_ok=True)
            file_path = os.path.join(user_folder, new_filename)
            file.save(file_path)
            cur.execute('INSERT INTO avatars (user_id, filename, upload_time) VALUES (?, ?, ?)',
                        (user_id, new_filename, time.strftime('%Y-%m-%d %H:%M:%S')))
            cur.execute('SELECT id, filename FROM avatars WHERE user_id=? ORDER BY upload_time DESC', (user_id,))
            records = cur.fetchall()
            if len(records) > 3:
                for rec in records[3:]:
                    try:
                        os.remove(os.path.join(app.config['UPLOAD_FOLDER'], username, rec['filename']))
                    except:
                        pass
                    cur.execute('DELETE FROM avatars WHERE id=?', (rec['id'],))
            conn.commit()
    cur.execute('SELECT filename, upload_time FROM avatars WHERE user_id=? ORDER BY upload_time DESC', (user_id,))
    avatars = cur.fetchall()
    conn.close()
    return render_template('profile.html', username=username, avatars=avatars)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8888, debug=True)
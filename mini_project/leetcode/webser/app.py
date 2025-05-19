from flask import Flask, render_template, request, session, redirect, url_for, jsonify
import random

app = Flask(__name__)
app.secret_key = 'super_secret_key'

def generate_captcha():
    a = random.randint(1, 10)
    b = random.randint(1, 10)
    op = random.choice(['+', '-', '*'])
    expression = f"{a} {op} {b}"
    answer = eval(expression)
    return expression, answer

@app.route('/')
def index():
    expression, answer = generate_captcha()
    session['captcha_answer'] = answer
    return render_template('index.html', captcha=expression)

@app.route('/refresh_captcha')
def refresh_captcha():
    expression, answer = generate_captcha()
    session['captcha_answer'] = answer
    return jsonify({'captcha': expression})

@app.route('/login', methods=['POST'])
def login():
    username = request.form.get('username')
    password = request.form.get('password')
    captcha_input = request.form.get('captcha')

    if 'captcha_answer' not in session or not captcha_input.isdigit() or int(captcha_input) != session['captcha_answer']:
        expression, answer = generate_captcha()
        session['captcha_answer'] = answer
        return render_template('index.html', captcha=expression, error='验证码错误，请重试！')

    if username == 'admin' and password == '123456':
        return "登录成功！"
    else:
        expression, answer = generate_captcha()
        session['captcha_answer'] = answer
        return render_template('index.html', captcha=expression, error='用户名或密码错误！')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8888, debug=True)

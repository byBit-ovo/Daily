# Flask 用户头像上传系统

## 功能
- 用户注册 / 登录 / 注销
- 上传头像（最多保存3个）
- 显示当前头像和历史头像
- SQLite 数据库存储
- 中文界面 + Bootstrap 样式

## 使用方法
1. 安装依赖：
   pip install flask

2. 初始化数据库：
   sqlite3 app.db < schema.sql

3. 启动：
   python app.py

访问 http://127.0.0.1:5000

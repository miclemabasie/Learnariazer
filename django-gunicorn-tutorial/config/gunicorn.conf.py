# gunicorn.conf.py
 
command = "/home/electron/Dev/Learnariazer/django-gunicorn-tutorial/env/bin/gunicorn"
pythonpath = "/home/electron/Dev/Learnariazer/django-gunicorn-tutorial/myproject"
bind = "0.0.0.0:8000"
workers = 3
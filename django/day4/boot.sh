!/bin/bash

PYTHON_PATH="/usr/bin/python3"
VEN_DIR="django_venv"

# setup venv
$PYTHON_PATH -m venv $VEN_DIR
source $VEN_DIR/bin/activate

###########server 
admin_DIR="mysite"
django-admin startproject d04
# python3 manage.py runserver
# python3 manage.py startapp pools
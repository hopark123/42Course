#!/bin/bash

PYTHON_PATH="/usr/bin/python3"
VEN_DIR="local_lib"
LOG_FILE="pip_install.log"

# setup venv
$PYTHON_PATH -m venv $VEN_DIR
source $VEN_DIR/bin/activate

# python version
python -m pip --version

# pip upgrade
pip install --upgrade pip

# pip install
python -m pip install -q -I requests dewiki


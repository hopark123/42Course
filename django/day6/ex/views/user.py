from random import choice
from django.shortcuts import render, redirect
from django.conf import settings
from django.http import HttpResponse
from django.views import View

def User(request) :
    return render(request, 'pages/main.html')


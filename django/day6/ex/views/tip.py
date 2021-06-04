from django.contrib.auth import authenticate, logout
from django.shortcuts import  redirect
import random
from ..forms import TipForm
from ..models import TipModel

def createtip(request):
    if request.method=='POST':
        form = TipForm(request.POST)
        if form.is_valid() :
            content = form.data.get('content')
            author = request.user
            if content:
                tip = TipModel(author=author, content=content)
                tip.save()
    return redirect('main')



from django import db
from django.views import View
from django.http import HttpResponse
from django.shortcuts import redirect, render
from ..models import Movies
from ..forms import RemoveForm

class Populate(View):
    def get(request) :
        res = ""
        for movie in data:
            try :
                new_movie = Movies(**movie)
                new_movie.save()
                res += "OK<br>"
            except Exception as e :
                res += str(e) + "<br>"
        return HttpResponse(res)

class Remove(View):
    template = "ex05/remove.html"
    def get(self, request) :
        res = ""
        
        try :
            response = Movies.objects.all()
        except Exception as e :
            return HttpResponse(e, "No data available")
        if response :
            choices=((movie[0], movie[0]) for movie in response)
            context = {"data" : RemoveForm(choices)}
            return render(request, 'self.template', context)
        else :
            return HttpResponse("No data available")
    
    def post(self, request) :
        res = ""
        try :
            response = Movies.objects.all()
        except Exception as e :
            return HttpResponse(e, "No data available")
        if response :
            choices=((movie[0], movie[0]) for movie in response)
            data = RemoveForm(choices, request.POST)
        if data.is_valid() == True:
            try:
                Movies.objects.get(title=data.clean_data['title']).delete(0)
            except Exception as e:
                res += str(e) + "<br>"
        print(res)
        return redirect(request.path)
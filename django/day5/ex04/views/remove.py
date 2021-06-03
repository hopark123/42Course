from django.conf import settings
from django.http import HttpResponse
from django.shortcuts import redirect, render
from django.views import View
from django.forms import Form
from ..forms import RemoveForm
import psycopg2

class Remove(View):
    connection = psycopg2.connect(
        database=settings.DATABASES['default']['NAME'],
        user=settings.DATABASES['default']['USER'],
        password=settings.DATABASES['default']['PASSWORD'],
        host=settings.DATABASES['default']['HOST'],
    )
    template = "ex04/remove.html"

    def get(self, request):
        response = None
        res = ""
        curs = self.connection.cursor()
        try:
            curs.execute("""SELECT * FROM ex04_movies""")
            response = curs.fetchall()
        except Exception as e:
            res += str(e)
        finally:
            if curs and not curs.closed:
                curs.close()
        if response :
            context = {'form' : RemoveForm(choices=((movie[0], movie[0]) for movie in response))}
            return render(request, self.template, context)
        else:
            return HttpResponse(res, "No data available")
    
    def post(self, request) :
        res = ""
        curs = self.connection.cursor()
        try:
            curs.execute("""SELECT * FROM ex04_movies""")
            response = curs.fetchall()
        except Exception as e:
            res += str(e)
        finally:
            if curs and not curs.closed:
                print("@")
                curs.close()
        if response :
            choices=((movie[0], movie[0]) for movie in response)
            movie = RemoveForm(choices, request.POST)
            try:
                curs.execute("""DELETE FROM ex04_movies WHERE title = data.cleaned_data['title']""")
                self.connection.commit()
            except Exception as e:
                res += str(e)
            finally:
                if curs and not curs.closed:
                    print("#")
                    curs.close()
        print(res)
        return redirect(request.path)


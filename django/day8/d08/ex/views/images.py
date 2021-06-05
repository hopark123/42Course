from django.shortcuts import render
from django.views.generic import DetailView, FormView,ListView
from ..models import ImagesModel
from ..forms import ImagesForm


class HomePageView(ListView):
    model = ImagesModel
    template_name = 'pages/main.html'

    def get_context_data(self, **kwargs):
        context = super(HomePageView, self).get_context_data(**kwargs)
        context['form'] = ImagesModel
        return context

    def post(self, request , *args , **kwargs):
        self.object = self.get_object()
        form = self.get_form()
        if form.is_valid():
            form.save()
            return self.form_valid(form)
        else:
            return self.form_invalid(form)

class ImgesView(FormView) :
    template_name = 'pages/main.html'
    form_class = ImagesForm
    success_url = "/"
    def form_valid(self, form) :
        form.save()
        return super(ImgesView, self).form_valid(form)
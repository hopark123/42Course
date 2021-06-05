from django.forms import ModelForm
from ..models import ImagesModel

class ImagesForm(ModelForm):
     class Meta:
        model = ImagesModel
        fields = ('images', 'title')
from django.conf import settings
from django.db import models


class ImagesModel(models.Model):
    title = models.CharField(max_length=255)
    images = models.ImageField(blank=True, upload_to="images/%Y/%m/%d")

    def __str__(self) -> str:
        return self.title
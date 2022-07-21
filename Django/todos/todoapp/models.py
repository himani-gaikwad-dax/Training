from django.db import models

# Create your models here.


class Mytodo(models.Model):
    id = models.AutoField(primary_key=True)
    task = models.CharField(max_length=50)
    description= models.TextField()
   
    def __str__(self):
        return self.task
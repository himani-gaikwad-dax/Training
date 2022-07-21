from django.urls import path
from . import views

urlpatterns = [
    path('', views.alltodos, name = 'alltodos'),
    path('delete/?P<int:id>/',views.delete,name="delete"),
    path('update/?P<int:id>/',views.update,name="update"),

]
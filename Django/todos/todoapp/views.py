from django.shortcuts import render, redirect
from .models import Mytodo

# Create your views here.

def alltodos(request):
    all_todos=Mytodo.objects.all()
    if request.method == 'POST':
        todo = Mytodo()
        todo.task= request.POST.get('task')
        todo.description = request.POST.get('description')
        todo.save()
    return render(request,'todos/alltodo.html',{'todos':all_todos})
   
def delete(request,id):
    Mytodo.objects.filter(id=id).delete()
    return redirect(alltodos)


def update(request,id):
   
    if request.method == "POST":
        todo = Mytodo.objects.get(id=id) 
        todo.task = request.POST.get('task')
        todo.description = request.POST.get('description')
        todo.save()
        return redirect(alltodos)

    todo= Mytodo.objects.all().filter(id=id)
    return render(request,'todos/update.html', {'task':todo[0].task , 'description':todo[0].description})
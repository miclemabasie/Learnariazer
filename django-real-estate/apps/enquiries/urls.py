from django.urls import path
from . import views

urlpatterns = [
    path("", views.send_enquiry_email, name="send_enquiry_email"),
]

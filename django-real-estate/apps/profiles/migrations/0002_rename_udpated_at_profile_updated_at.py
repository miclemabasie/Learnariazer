# Generated by Django 3.2.7 on 2023-12-17 11:07

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('profiles', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='profile',
            old_name='udpated_at',
            new_name='updated_at',
        ),
    ]
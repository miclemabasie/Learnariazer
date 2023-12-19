# Generated by Django 3.2.7 on 2023-12-19 00:07

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('profiles', '0002_rename_udpated_at_profile_updated_at'),
        ('ratings', '0002_rename_udpated_at_rating_updated_at'),
    ]

    operations = [
        migrations.AlterField(
            model_name='rating',
            name='agent',
            field=models.ForeignKey(null=True, on_delete=django.db.models.deletion.SET_NULL, related_name='agent_reviews', to='profiles.profile', verbose_name='Agent being rated'),
        ),
    ]
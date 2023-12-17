from rest_framework import serializers
from .models import Property, PropertyViews
from django_countries.serializer_fields import CountryField
from django_countries.serializers import CountryFieldMixin
from django_countries import countries


class PropertySerializer(CountryFieldMixin, serializers.ModelSerializer):
    user = serializers.SerializerMethodField()
    country = CountryField(country_dict=True)
    property_type = serializers.ChoiceField(choices=Property.PROPERTY_TYPES)
    published_status = serializers.ChoiceField(choices=Property.PUBLISHED_STATUS)
    slug = serializers.SlugField(read_only=True)
    created_at = serializers.DateTimeField(read_only=True)
    updated_at = serializers.DateTimeField(read_only=True)

    class Meta:
        model = Property
        fields = (
            "id",
            "title",
            "slug",
            "ref_code",
            "country",
            "city",
            "postal_code",
            "price",
            "property_type",
            "published_status",
            "description",
            "created_at",
            "updated_at",
            "user",
            "cover_image",
            "photo_1",
            "photo_2",
            "photo_3",
            "tax",
            "final_property_price",
            "plot_area",
            "total_floors",
            "bedrooms",
            "bathrooms",
            "advert_type",
            "street_address",
            "published_status",
            "views",
            "currency",
            "garages",
            "property_number",
            "arear_measurement",
            "year_built",
        )

    def get_user(self, obj):
        return obj.user.username


class PropertyCreateSerializer(serializers.ModelSerializer):
    country = CountryField(country_dict=True)

    class Meta:
        model = Property
        exclude = (
            "pkid",
            "slug",
            "created_at",
            "updated_at",
            "views",
            "published_status",
        )

    def get_user(self, obj):
        return obj.user.username


class PropertyViewSerializer(serializers.ModelSerializer):
    class Meta:
        model = PropertyViews
        exclude = ("updated_at", "pkid")

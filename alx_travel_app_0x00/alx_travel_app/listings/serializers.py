from rest_framework import serializers
from .models import Listing , Booking

class ListingSerializer(serializers.ModelSerializer):
    class Meta:
        model = Listing
        fields = ['id', 'title', 'description', 'price_per_night', 'location', 'created_at']
        read_only_fields = ['property_id', 'created_at', 'updated_at']

class BookingSerializer(serializers.ModelSerializer):
    class Meta:
        model = Booking
        fields = ['id', 'user', 'listing', 'check_in', 'check_out', 'total_price']
        read_only_fields = ['booking_id', 'created_at']
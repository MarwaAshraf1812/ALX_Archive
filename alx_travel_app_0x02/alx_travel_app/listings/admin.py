from django.contrib import admin
from listings.models import Listing, Booking, Review


@admin.register(Listing)
class ListingAdmin(admin.ModelAdmin):
    list_display = ['id', 'title', 'description', 'price_per_night', 'location', 'created_at']

@admin.register(Booking)
class BookingAdmin(admin.ModelAdmin):
    list_display = ['id', 'user', 'listing', 'check_in', 'check_out', 'total_price']


@admin.register(Review)
class ReviewAdmin(admin.ModelAdmin):
    list_display = ['id', 'user', 'listing', 'rating', 'comment', 'created_at']

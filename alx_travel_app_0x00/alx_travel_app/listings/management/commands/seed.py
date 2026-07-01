from django.core.management.base import BaseCommand
from listings.models import Listing
from django.contrib.auth.models import User



class Command(BaseCommand):
  help = 'seed the database with some initial data'

  def handle(self, *args, **options):
    if User.objects.count() == 0:
      User.objects.create_superuser(username='admin', password='admin123')
    
    sample_data = [
      {
        'title': 'Luxury Villa in Bali',
        'description': 'Beautiful villa with 5 bedrooms, a private pool, and a view of the ocean',
        'price_per_night': 500.00,
        'location': 'Bali, Indonesia'
      },
      {
        'title': 'Ski Chalet in the Alps',
        'description': 'Cozy chalet with a fireplace and a view of the mountains',
        'price_per_night': 300.00,
        'location': 'French Alps'
      }
    ]

    for data in sample_data:
      Listing.objects.create(**data)
      self.stdout.write(self.style.SUCCESS('Successfully seeded the database'))
#!/usr/bin/python3
"""
BasicCache module
"""

BaseCaching = __import__('base_caching').BaseCaching

class FIFOCache(BaseCaching):
    """
    FIFOCache class
    """

    def __init__(self):
        """
            A FIFO Cache.
            Inherits all behaviors from BaseCaching except, upon any attempt to
            add an entry to the cache when it is at max capacity (as specified by
            BaseCaching.MAX_ITEMS), it discards the oldest entry to accommodate for
            the new one."""

        super().__init__()
        self.keys = []

    def put(self, key, item):
        """
        The put method will be responsible for
        adding key-item pairs to the cache and
        handling the cache size limit (MAX_ITEMS).
        """
        if key and item is not None:
            self.cache_data[key] = item
        
            if key not in self.keys:
                self.keys.append(key)
            if len(self.keys) > BaseCaching.MAX_ITEMS:
                first_item = self.keys.pop(0)
                del self.cache_data[first_item]
                print("DISCARD: {}".format(first_item))

    def get(self, key):
        """
        The get method will be responsible for
        returning the value associated with a
        given key, or None if the key is
        not present in the cache.
        """

        if key is not None and key in self.cache_data:
            return self.cache_data.get(key)
        return None
            
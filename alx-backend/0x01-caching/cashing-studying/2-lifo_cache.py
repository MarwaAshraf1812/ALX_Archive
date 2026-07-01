#!/usr/bin/python3
"""
BasicCache module
"""

BaseCaching = __import__('base_caching').BaseCaching

class LIFOCache(BaseCaching):
    """
    LIFOCache class
    """

    def __init__(self):
        """A LIFO Cache."""

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
                last_item = self.keys.pop()
                del self.cache_data[last_item]
                print("DISCARD: {}".format(last_item))

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
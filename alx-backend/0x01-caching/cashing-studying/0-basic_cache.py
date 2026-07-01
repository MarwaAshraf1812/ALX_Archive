#!/usr/bin/python3
"""
BasicCache module
"""

BaseCaching = __import__('base_caching').BaseCaching

class BasicCache (BaseCaching):
    """
    BasicCache class
    """

    def put(self, key, item):
        """
        The put method will be responsible for
        adding key-item pairs to the cache and
        handling the cache size limit (MAX_ITEMS).
        """
        if key or item is not None:
            self.cache_data[key] = item


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

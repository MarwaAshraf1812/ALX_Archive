#!/usr/bin/python3
"""
MRU Cache
"""

BaseCaching = __import__('base_caching').BaseCaching


class MRUCache(BaseCaching):
    """
    MRU Cache class
    """

    def __init__(self):
        """MRU Cache initializer.
        -- MRU removes the data that was used most
           recently when it needs to free up space.
        """

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
            else:
               self.keys.append(self.keys.pop(self.keys.index(key)))

            if len(self.keys) > BaseCaching.MAX_ITEMS:
                discard_item = self.keys.pop(-2)
                del self.cache_data[discard_item]
                print("DISCARD: {}".format(discard_item))

    def get(self, key):
        """
        The get method will be responsible for
        returning the value associated with a
        given key, or None if the key is
        not present in the cache.
        """

        if key is not None and key in self.cache_data:
            self.keys.append(self.keys.pop(self.keys.index(key)))
            return self.cache_data.get(key)
        return None
            


#!/usr/bin/python3
"""
LRU Cache
"""

BaseCaching = __import__('base_caching').BaseCaching


class LRUCache(BaseCaching):
    """
    LRU Cache class
    """

    def __init__(self):
        """A LRU Cache initializer..
        -- LRU removes the data that hasn’t been used for the longest time."""

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
                """
                This line of code performs the following actions:

                Find the Index of the Key: self.keys.index(key)

                This finds the index of the key in the list self.keys.
                Remove the Key from Its Current Position: self.keys.pop(self.keys.index(key))

                This removes the key from the list at the position found in 
                the previous step and returns the removed key.
                Append the Key to the End of the List: self.keys.append(...)

                This appends the key (removed in the previous step) to the end of the list self.keys.
                
                ==> This ensures that the accessed key is 
                    moved to the end of the list, 
                    indicating that it is the most recently used key.
                """
                self.keys.append(self.keys.pop(self.keys.index(key)))

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
            self.keys.append(self.keys.pop(self.keys.index(key)))
            return self.cache_data.get(key)
        return None
            

from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.cache:
            self.cache.move_to_end(key)
            return self.cache[key]
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key) //Move to the most frequent used position
        
        self.cache[key] = value //Update key value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
            

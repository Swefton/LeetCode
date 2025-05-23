from collections import deque

class LRUCache:

    def __init__(self, capacity: int):
        self.queue = deque()
        self.cache = dict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            if key in self.queue:
                del self.queue[self.queue.index(key)]
            self.queue.append(key)

            return self.cache[key]

        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.queue.remove(key)
        elif len(self.cache) >= self.capacity:
            del self.cache[self.queue.popleft()]

        self.queue.append(key)
        self.cache[key] = value



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
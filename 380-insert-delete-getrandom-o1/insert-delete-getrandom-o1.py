class RandomizedSet:
    def __init__(self):
        self.item_to_position = {}
        self.items = []

    def insert(self, val: int) -> bool:
        if val in self.item_to_position:
            return False
        self.items.append(val)
        self.item_to_position[val] = len(self.items)-1
        return True

    def remove(self, val: int) -> bool:
        if val in self.item_to_position:
            position = self.item_to_position.pop(val)
            last_item = self.items.pop()
            if position != len(self.items):
                self.items[position] = last_item
                self.item_to_position[last_item] = position
            return True
        else:
            return False

    def getRandom(self) -> int:
        return random.choice(self.items)

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
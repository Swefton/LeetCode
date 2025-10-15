"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = root

        queue = [root] if root else []

        while queue:
            for i in range(len(queue)-1):
                queue[i].next = queue[i+1]
            
            next_level = list()
            
            for node in queue:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            queue = next_level

        return head
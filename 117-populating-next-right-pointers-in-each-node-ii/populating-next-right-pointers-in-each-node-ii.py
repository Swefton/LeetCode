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
            
            
            queue = temp = [child for node in queue for child in (node.left, node.right) if child]


        return head
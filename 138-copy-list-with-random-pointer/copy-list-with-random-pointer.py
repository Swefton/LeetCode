"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        copy_head = Node(0)
        curr = copy_head
        copy_struct = dict()
        
        while head:
            curr.val = head.val
            curr.random = head.random
            copy_struct[head] = curr


            head = head.next

            if head:
                new = Node(0)
                curr.next = new
                curr = curr.next

        
        curr = copy_head

        while curr:
            curr.random = copy_struct[curr.random] if curr.random else None
            curr = curr.next

        return copy_head
        

        
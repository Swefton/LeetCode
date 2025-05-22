# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = head
        curr = head
        prev = None
        while curr:
            dummy = curr.next
            if prev:
                curr.next = prev
            prev = curr
            curr = dummy
        
        if front:
            front.next = None
        return prev

        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head

        curr = head
        prev = None
        pos = 1
        
        before_reverse, after_reverse = None, None 
        reverse_start, reverse_end = None, None

        while curr:
            next_node = curr.next

            if left <= pos <= right:
                if pos == left:
                    before_reverse = prev
                    reverse_start = curr
                elif pos == right:
                    after_reverse = next_node
                    reverse_end = curr
                curr.next = prev

            prev = curr
            curr = next_node
            pos += 1

        if before_reverse:
            before_reverse.next = reverse_end
        else:
            head = reverse_end

        reverse_start.next = after_reverse

        return head

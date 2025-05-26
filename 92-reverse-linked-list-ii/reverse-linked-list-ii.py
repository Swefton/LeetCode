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
        
        # These will help reconnect the reversed sublist later
        left_start = None  # Node before `left`
        connector_left = None  # Node at position `left`
        right_end = None  # Node after `right`
        connector_right = None  # Node at position `right`

        # Traverse and reverse only the [left, right] portion
        while curr:
            next_node = curr.next

            if left <= pos <= right:
                if pos == left:
                    left_start = prev
                    connector_left = curr
                elif pos == right:
                    right_end = next_node
                    connector_right = curr
                curr.next = prev  # Reverse the link

            prev = curr
            curr = next_node
            pos += 1

        # Reconnect the reversed portion with the rest of the list
        # Fix: handle the case where reversal starts from head (left == 1)
        if left_start:
            left_start.next = connector_right
        else:
            head = connector_right  # New head if reversal started at the head

        connector_left.next = right_end

        return head

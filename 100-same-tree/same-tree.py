# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue1, queue2 = deque(), deque()

        queue1.append(p)
        queue2.append(q)

        while queue1 or queue2:
            p = queue1.popleft()
            q = queue2.popleft()

            if (p.val if p else None) == (q.val if q else None):
                pass
            else:
                return False

            queue1.extend([p.left, p.right]) if p else None
            queue2.extend([q.left, q.right]) if q else None

        return True
        
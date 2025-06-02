# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        queue = deque([root]) if root else deque()

        while queue:
            item = queue.popleft()
            queue.append(item.left) if item.left else None
            queue.append(item.right) if item.right else None
            
            item.left, item.right = item.right, item.left


        return root
        
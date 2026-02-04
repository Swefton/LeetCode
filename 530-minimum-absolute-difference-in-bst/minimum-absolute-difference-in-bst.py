# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        prev, diff = None, float("inf")

        def inorder(node):
            nonlocal prev, diff
            if not node:
                return

            inorder(node.left)
            if prev:
                diff = min(diff, node.val - prev.val)
            prev = node
            inorder(node.right)

        inorder(root)
        return diff

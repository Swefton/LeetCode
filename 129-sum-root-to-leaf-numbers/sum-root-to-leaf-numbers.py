# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def Backtrack(node, number):
            if not (node.left or node.right):
                return number

            total = 0
            for child in (node.left, node.right):
                if child:
                    total += Backtrack(child, number * 10 + child.val)
            return total

        return Backtrack(root, root.val)

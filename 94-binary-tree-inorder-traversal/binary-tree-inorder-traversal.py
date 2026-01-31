# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = list()

        def traversal(node):
            if not node:
                return

            traversal(node.left)
            result.append(node.val)
            traversal(node.right)

        traversal(root)

        return result
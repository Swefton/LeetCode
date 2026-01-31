# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        count = [1]

        def dfs(node):
            if not node:
                return

            for child in [node.left, node.right]:
                if child:
                    count[0] = count[0] + 1
                    dfs(child)
            
        dfs(root)

        return count[0]

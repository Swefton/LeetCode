# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if not root:
                return (-float('inf'), 0)

            left_max, left_gain = dfs(root.left)
            right_max, right_gain = dfs(root.right)

            subtree_max = max(left_max, right_max, root.val + left_gain + right_gain)
            upward_gain = max(root.val + max(left_gain, right_gain), 0)

            return subtree_max, upward_gain

        return dfs(root)[0]
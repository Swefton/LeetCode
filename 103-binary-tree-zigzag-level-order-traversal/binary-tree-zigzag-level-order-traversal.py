# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = [root] if root else []
        right = True
        results = []

        while queue:
            results.append([node.val for node in queue] if right else [node.val for node in queue[::-1]])
            queue = [child for node in queue for child in (node.left, node.right) if child] 
            right = not right

        return results
        
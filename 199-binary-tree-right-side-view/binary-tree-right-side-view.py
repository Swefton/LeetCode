# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
            
        results = list()

        queue = [root]
        
        while queue:
            results.append(queue[-1].val)

            temp = list()
            for node in queue:
                for item in (node.left, node.right):
                    if item:
                        temp.append(item)
                
            queue = temp

        return results 
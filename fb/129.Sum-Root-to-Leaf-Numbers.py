# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:        
        def dfs(node, pathValue):
            nonlocal pathSum
            if node is None:
                return
            if node.left is None and node.right is None:
                pathSum += pathValue * 10 + node.val
                return
            dfs(node.left, pathValue * 10 + node.val)
            dfs(node.right, pathValue * 10 + node.val)
            
            
        pathSum = 0
        dfs(root, 0)
        return pathSum

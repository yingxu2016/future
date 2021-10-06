# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isMirror(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            
            return left.val == right.val and isMirror(left = left.left, right = right.right) and isMirror(left = left.right, right = right.left)
        
        return isMirror(left = root, right = root)

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        queue = [root, root]
        while len(queue) > 0:
            left = queue.pop(0)
            right = queue.pop(0)
            if left is None and right is None:
                continue
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            
            queue = queue + [left.left, right.right, left.right, right.left]
            
        return True

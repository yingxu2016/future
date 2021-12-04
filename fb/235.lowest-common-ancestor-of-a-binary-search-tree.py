# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parentVal = root.val
        pVal = p.val
        qVal = q.val
        if pVal < parentVal and qVal < parentVal:
            return self.lowestCommonAncestor(root.left, p, q)
        elif pVal > parentVal and qVal > parentVal:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root

class Solution2:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pVal = p.val
        qVal = q.val
        node = root
        while node:
            parentVal = node.val
            if pVal < parentVal and qVal < parentVal:
                node = node.left
            elif pVal > parentVal and qVal > parentVal:
                node = node.right
            else:
                return node

# slowest - need to traverse the entire tree
class Solution3:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':        
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        return left if left else right

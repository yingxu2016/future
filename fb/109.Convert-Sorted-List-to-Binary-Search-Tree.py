# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countSize(self, head):
        count = 0
        while head:
            head = head.next
            count += 1
        return count
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def recursion(left, right):
            nonlocal head
            if left > right:
                return None
            
            mid = left + (right-left)//2
            left = recursion(left, mid-1)
            
            root = TreeNode(head.val)
            root.left = left
            
            head = head.next
            
            root.right = recursion(mid+1, right)
            return root
        
        return recursion(0, self.countSize(head)-1)

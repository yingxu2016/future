# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        fakeHead = ListNode(0)
        pointer = fakeHead
        
        while head:
            if head.val != val:
                pointer.next = ListNode(head.val)
                pointer = pointer.next
            head = head.next
            
        return fakeHead.next

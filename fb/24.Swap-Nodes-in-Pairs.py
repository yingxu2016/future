# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fakeHead = ListNode(0, head)
        pre = fakeHead
        
        while pre.next and pre.next.next:
            first = pre
            second = pre.next
            third = pre.next.next
            
            second.next = third.next
            third.next = second
            first.next = third
            
            pre = second
        return fakeHead.next

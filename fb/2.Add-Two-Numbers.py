# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0)
        pointer = head
        carry = 0
        
        while l1 or l2 or carry:
            num1 = l1.val if l1 else 0
            num2 = l2.val if l2 else 0
            carry, num = divmod(num1 + num2 + carry, 10)
            
            pointer.next = ListNode(num)
            pointer = pointer.next
            
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return head.next

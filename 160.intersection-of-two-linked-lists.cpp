/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        int la = 0;
        int lb = 0;
        ListNode* _headA = headA;
        ListNode* _headB = headB;
        while(_headA) {
            la++;
            _headA = _headA->next;
        }
        while(_headB) {
            lb++;
            _headB = _headB->next;
        }
        ListNode* tmp = la >= lb ? headA : headB;
        for(int i = 0; i < abs(la - lb); i++) {
            tmp = tmp->next;
        }
        la >= lb ? headA = tmp : headB = tmp;
        while(headA && headB) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

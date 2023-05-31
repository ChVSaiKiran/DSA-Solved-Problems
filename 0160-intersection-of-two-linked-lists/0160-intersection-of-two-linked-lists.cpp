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
        ListNode *t1 = headA;
        while(t1 -> next)
            t1 = t1 -> next;
        t1 -> next = headB;
        ListNode *slow = headA, *fast = headA;
        while(fast && fast -> next){
            slow = slow -> next, fast = fast -> next -> next;
            if(fast == slow)
                break;
        }
        if(!fast || !fast -> next){
            t1 -> next = nullptr;
            return nullptr;
        }
        fast = headA;
        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }
        t1 -> next = nullptr;
        return slow;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head -> next)
            return head;
        ListNode t1, t2;
        ListNode *h1 = &t1, *h2 = &t2;
        while(head){
            if(head -> val < x)
                h1 -> next = head, h1 = h1 -> next;
            else
                h2 -> next = head, h2 = h2 -> next;
            head = head -> next;
        }
        h1 -> next = t2.next;
        h2 -> next = nullptr;
        return t1.next ? t1.next : t2.next;
    }
};
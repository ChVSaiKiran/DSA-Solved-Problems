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
    ListNode* merge(ListNode *h1, ListNode *h2){
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode node, *curr = &node;
        while(h1 && h2){
            if(h1 -> val < h2 -> val){
                curr -> next = h1;
                h1 = h1 -> next;
            }
            else{
                curr -> next = h2;
                h2 = h2 -> next;
            }
            curr = curr -> next;
        }
        if(h1)
            curr -> next = h1;
        if(h2)
            curr -> next = h2;
        return node.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *temp = nullptr, *slow = head, *fast = head;
        while(fast && fast -> next){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        temp -> next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1,l2);
    }
};
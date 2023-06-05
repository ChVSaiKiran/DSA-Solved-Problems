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
    ListNode* getmiddle(ListNode *head){
        ListNode *slow = head, *fast = head, *prev;
        while(fast && fast -> next)
            prev = slow, slow = slow -> next, fast = fast -> next -> next;
        return prev;
    }
    ListNode* reverse(ListNode *head){
        ListNode *curr = head, *prev = nullptr, *temp = head;
        while(curr){
            temp = temp -> next,curr -> next = prev;
            prev = curr,curr = temp;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next)
            return;
        ListNode *mid = getmiddle(head);
        ListNode *h1 = head, *h2 = reverse(mid -> next);
        mid -> next = nullptr;
        ListNode dumb, *temp = &dumb;
        while(h1 && h2){
            temp -> next = h1, temp = temp -> next;
            h1 = h1 -> next;
            temp -> next = h2, temp = temp -> next;
            h2 = h2 -> next;
        }
    }
};
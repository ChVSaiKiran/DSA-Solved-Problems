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
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *temp = head, *prev = nullptr;
        while(curr){
            temp = temp -> next, curr -> next = prev;
            prev = curr, curr = temp;
        }
        return prev;
    }
    int count(ListNode *head){
        int cnt = 0;
        while(head)
            head = head -> next, cnt++;
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next)
            return head;
        int n = count(head);
        k = k % n;
        if(k == 0)  return head;
        head = reverse(head);
        ListNode *temp = head;
        while(k > 1)    temp = temp -> next, k--;
        ListNode *h1 = head, *h2 = temp -> next;
        temp -> next = nullptr;
        h1 = reverse(h1), h2 = reverse(h2);
        head = h1;
        while(h1 -> next)
            h1 = h1 -> next;
        h1 -> next = h2;
        return head;
    }
};
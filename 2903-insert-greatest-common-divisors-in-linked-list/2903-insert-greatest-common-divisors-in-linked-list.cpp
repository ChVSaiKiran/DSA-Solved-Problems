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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int prev = head -> val;
        ListNode *curr = head -> next;
        ListNode *tail = head;
        while(curr != nullptr){
            tail -> next = new ListNode(__gcd(prev, curr -> val));
            tail = tail -> next;
            tail -> next = curr;

            prev = curr -> val;
            curr = curr -> next;
            tail = tail -> next;
        }
        return head;
    }
};
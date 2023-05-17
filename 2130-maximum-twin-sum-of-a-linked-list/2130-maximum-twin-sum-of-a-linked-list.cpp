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
        while(temp){
            temp = temp -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev;
        while(fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        fast = reverse(slow);
        slow = head;
        int maxi = 0;
        while(fast){
            maxi = max(maxi, slow -> val + fast -> val);
            slow = slow -> next;
            fast = fast -> next;
        }
        return maxi;
    }
};
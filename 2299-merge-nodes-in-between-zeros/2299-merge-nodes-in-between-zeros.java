/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode curr) {
        int sum = 0;
        do{
            curr = curr.next;
            sum += curr.val;
        } while(curr.val != 0);
        ListNode ans = new ListNode(sum);
        if(curr.next != null)
            ans.next = mergeNodes(curr);
        return ans;
    }
}
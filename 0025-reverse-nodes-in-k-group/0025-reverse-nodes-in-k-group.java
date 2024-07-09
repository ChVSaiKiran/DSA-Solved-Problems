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
    private ListNode rmngHead = null;
    private ListNode reverseKNodes(ListNode curr, int k){
        if(k == 1){
            rmngHead = curr.next;
            curr.next = null;
            return curr;
        } else if(curr.next == null){
            return null;
        } else{
            ListNode reverseHead = reverseKNodes(curr.next, k - 1);
            if(reverseHead != null){
                curr.next.next = curr;
            }
            return reverseHead;
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k == 1){
            return head;
        }
        ListNode ans = reverseKNodes(head, k), tail = head;
        if(ans == null){
            return head;
        } else{
            tail.next = rmngHead;
        }

        while(rmngHead != null){
            ListNode temp = rmngHead, kHead = reverseKNodes(rmngHead, k);
            if(kHead != null){
                tail.next = kHead;
                tail = temp;
            } else{
                break;
            }
            tail.next = rmngHead;
        }

        return ans;
    }
}
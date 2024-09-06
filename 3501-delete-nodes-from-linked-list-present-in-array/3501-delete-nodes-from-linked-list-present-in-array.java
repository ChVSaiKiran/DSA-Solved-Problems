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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> st = new HashSet<>();
        for(int i : nums){
            st.add(i);
        }

        ListNode curr = head, ans = null, tail = null;
        while(curr != null){
            if(!st.contains(curr.val)){
                if(ans == null){
                    ans = curr;
                    tail = curr;
                } else{
                    tail.next = curr;
                    tail = tail.next;
                }
            }
            curr = curr.next;
        }
        tail.next = null;
        return ans;
    }
}
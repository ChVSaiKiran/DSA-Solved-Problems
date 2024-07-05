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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode curr = head.next;
        int cnt = 1, lt = -1, prev = -1, minDistance = (int)1e5, maxDistance = 0;
        int a = head.val, b = curr.val;
        while(curr.next != null){
            int c = curr.next.val;
            if((a < b && b > c) || (a > b && b < c)){
                if(lt == -1){
                    lt = cnt;
                } else{
                    minDistance = Math.min(minDistance, cnt - prev);
                    maxDistance = Math.max(maxDistance, cnt - lt);
                }
                prev = cnt;
            }
            a = b;
            b = c;
            cnt++;
            curr = curr.next;
        }
        int ans[] = new int[2];
        if (maxDistance == 0){
            ans[0] = -1;
            ans[1] =  -1;
        } else{
            ans[0] = minDistance;
            ans[1] = maxDistance;
        }
        return ans;
    }
}
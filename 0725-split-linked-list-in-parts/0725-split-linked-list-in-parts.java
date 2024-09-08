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
    private int count(ListNode temp){
        int cnt = 0;
        while(temp != null){
            cnt++;
            temp = temp.next;
        }
        return cnt;
    }

    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = count(head);
        ListNode ans[] = new ListNode[k];
        ListNode curr = head;

        int q = n / k, re = n % k;
        for(int i = 0; i < k; i++){
            ListNode Head = null, Tail = null;
            int m = q;
            if(re > 0){
                m++; re--;
            }

            for(int j = 0; j < m; j++){
                if(Head == null){
                    Head = curr;
                    Tail = curr;
                } else{
                    Tail.next = curr;
                    Tail = Tail.next;
                }
                curr = curr.next;
            }

            if(Tail != null){
                Tail.next = null;
            }
            
            ans[i] = Head;
        }

        return ans;
    }
}
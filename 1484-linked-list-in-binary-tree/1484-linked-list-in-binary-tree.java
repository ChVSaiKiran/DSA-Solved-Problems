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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean f(ListNode head, TreeNode root, boolean flag) {
        if(head == null){
            return true;
        }

        if(root == null){
            return false;
        }

        if(flag){
            if(head.val != root.val){
                return false;
            }

            boolean lt = f(head.next, root.left, true);
            boolean rt = f(head.next, root.right, true);
            return lt || rt;
        }
        
        if(head.val == root.val){
            boolean lt = f(head.next, root.left, true);
            boolean rt = f(head.next, root.right, true);
            if(lt || rt){
                return true;
            }
        }

        boolean lt = f(head, root.left, false);
        boolean rt = f(head, root.right, false);

        return lt || rt;
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        return f(head, root, false);
    }
}
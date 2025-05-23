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
    private boolean isLeaf(TreeNode root){
        return root != null && root.left == null && root.right == null;
    }

    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null){
            return 0;
        }

        return (isLeaf(root.left) ? root.left.val : (0 + sumOfLeftLeaves(root.left))) + sumOfLeftLeaves(root.right);
    }
}
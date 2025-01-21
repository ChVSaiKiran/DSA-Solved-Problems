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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int maxVal = nums[0];
        TreeNode root = new TreeNode(nums[0]);

        Stack<TreeNode> s = new Stack<>();
        s.add(root);

        for(int i = 1; i < nums.length; i++){
            TreeNode newnode = new TreeNode(nums[i]);
            TreeNode temp = null;

            if(maxVal < nums[i]){
                maxVal = nums[i];
                root = newnode;
            }

            while(!s.isEmpty() && s.peek().val < nums[i]){
                temp = s.peek();
                s.pop();
            }

            if(!s.isEmpty()){
                newnode.left = s.peek().right;
                s.peek().right = newnode;
            } else{
                newnode.left = temp; 
            }

            s.add(newnode);
        }

        return root;
    }
}
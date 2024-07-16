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
    private TreeNode ancestor;
    private boolean getCommonAncestor(TreeNode root, int startValue, int destValue){
        if(root == null){
            return false;
        }
        boolean left = getCommonAncestor(root.left, startValue, destValue);
        boolean right = getCommonAncestor(root.right, startValue, destValue);
        if((left && right)){
            ancestor = root;
            return false;
        }
        else if(left || right){
            if(root.val == startValue || root.val == destValue){
                ancestor = root;
                return false;
            } else{
                return true;
            }
        }
        return root.val == startValue || root.val == destValue;
    }
    
    private boolean f(TreeNode root, int val, boolean flag, StringBuilder s) {
        if (root == null) {
            return false;
        } else if (root.val == val) {
            return true;
        } else {
            boolean left = f(root.left, val, flag, s);
            boolean right = f(root.right, val, flag, s);
            if (left) {
                if (flag) {
                    s.append("U");
                } else {
                    s.append("L");
                }
                return true;
            }
            if (right) {
                if (flag) {
                    s.append("U");
                } else {
                    s.append("R");
                }
                return true;
            }
            return false;
        }
    }

    public String getDirections(TreeNode root, int startValue, int destValue) {
        getCommonAncestor(root, startValue, destValue);
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        f(ancestor, startValue, true, s1);
        f(ancestor, destValue, false, s2);
        return s1.toString() + s2.reverse().toString();
    }
}
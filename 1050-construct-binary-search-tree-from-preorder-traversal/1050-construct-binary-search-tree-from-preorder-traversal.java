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
    private TreeNode fun(int[] preorder, int[] nge, int l, int r){
        if(l > r){
            return null;
        }
        TreeNode root = new TreeNode(preorder[l]);
        if(nge[l] != -1){
            root.left = fun(preorder, nge, l + 1, nge[l] - 1);
            root.right = fun(preorder, nge, nge[l], r);
        } else{
            root.left = fun(preorder, nge, l + 1, r);
        }
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length, nge[] = new int[n];
        Arrays.fill(nge, -1);

        Stack<Integer> s = new Stack<>();

        for(int i = 0; i < n; i++){
            while(!s.isEmpty() && preorder[s.peek()] < preorder[i]){
                nge[s.peek()] = i;
                s.pop();
            }
            s.push(i);
        }
        return fun(preorder, nge, 0, preorder.length - 1);
    }
}
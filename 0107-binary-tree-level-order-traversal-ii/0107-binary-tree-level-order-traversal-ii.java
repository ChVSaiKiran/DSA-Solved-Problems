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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null){
            return Collections.emptyList();
        }

        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>(List.of(root));
        
        while(!q.isEmpty()){
            int n = q.size();
            List<Integer> level = new ArrayList<>();
            while(n-- > 0){
                root = q.poll();
                if(root.left != null){
                    q.add(root.left);
                }

                if(root.right != null){
                    q.add(root.right);
                }
                level.add(root.val);
            }
            ans.add(level);
        }
        Collections.reverse(ans);
        return ans;
    }
}
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
    private void f(TreeNode root, HashSet<Integer> s){
        if(root == null){
            return;
        }
        if(s.contains(root.val)){
            root.val = 0;
        }
        f(root.left, s);
        f(root.right, s);
    }

    private boolean fun(TreeNode root, List<TreeNode> ans){
        if(root == null){
            return false;
        }
        boolean lt = fun(root.left, ans), rt = fun(root.right, ans), flag = root.val == 0;
        if(flag){
            if(lt){
                root.left = null;
            } else if(root.left != null){
                ans.add(root.left);
            }
            if(rt){
                root.right = null;
            } else if(root.right != null){
                ans.add(root.right);
            }
            return true;
        }
        if(lt){
            root.left = null;
        }

        if(rt){
            root.right = null;
        }
        return false;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        HashSet<Integer> s = new HashSet<>();
        for(int i : to_delete){
            s.add(i);
        }
        f(root, s);
        List<TreeNode> ans = new ArrayList<>();
        if(root.val != 0)
            ans.add(root);
        fun(root, ans);
        return ans;
    }
}
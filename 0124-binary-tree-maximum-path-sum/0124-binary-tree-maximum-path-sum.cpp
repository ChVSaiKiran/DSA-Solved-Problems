/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int fun(TreeNode* root, long &ans){
        if(!root){
            return INT_MIN;
        }

        long val = root -> val;
        long lt = fun(root -> left, ans);
        long rt = fun(root -> right, ans);

        ans = max({ans, lt + rt + val, lt + val, rt + val, val});

        return max({lt + val, rt + val, val});
    }
public:
    int maxPathSum(TreeNode* root) {
        long ans = INT_MIN;  fun(root, ans);
        return ans;
    }
};
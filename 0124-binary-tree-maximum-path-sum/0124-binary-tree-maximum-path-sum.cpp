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
    int f(TreeNode *root, int &ans){
        if(root == nullptr){
            return 0;
        }

        int lt = f(root -> left, ans);
        int rt = f(root -> right, ans);

        ans = max(ans, max({root -> val, lt + root -> val, rt + root -> val, lt + rt + root -> val}));

        return max({root -> val, lt + root -> val, rt + root -> val});
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root, ans);
        return ans;
    }
};
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
    bool isLeaf(TreeNode *root){
        return root -> left == nullptr && root -> right == nullptr;
    }

    int fun(TreeNode* root, int xr){
        if(root == nullptr){
            return 0;
        }

        xr ^= (1 << root -> val);
        if(isLeaf(root)){
            return xr == 0 || ((xr & (xr - 1)) == 0);
        }

        return fun(root -> left, xr) + fun(root -> right, xr);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return fun(root, 0);
    }
};
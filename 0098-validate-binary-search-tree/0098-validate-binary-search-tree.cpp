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
    bool f(TreeNode* root, long l, long r){
        if(root == nullptr) return true;
        int val = root -> val;
        return val > l && val < r && f(root -> left, l, val) && f(root -> right, val, r);
    }

public:
    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};
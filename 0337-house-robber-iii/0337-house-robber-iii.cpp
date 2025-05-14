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
    pair<long,long> fun(TreeNode* root){
        if(root == nullptr){
            return make_pair(0, 0);
        }

        auto lt = fun(root -> left); //not Pick, pick
        auto rt = fun(root -> right); //not Pick, pick

        long pick = lt.first + rt.first + root -> val;
        long notPick = max({lt.second + rt.second, lt.first + rt.second, lt.second + rt.first, lt.first + rt.first});
        return make_pair(notPick, pick);
    }
public:
    int rob(TreeNode* root) {
        auto it = fun(root);
        return max(it.first, it.second);
    }
};
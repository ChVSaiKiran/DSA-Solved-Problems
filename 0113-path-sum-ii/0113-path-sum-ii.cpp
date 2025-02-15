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
    void fun(TreeNode *root, int target, vector<int> temp, vector<vector<int>> &ans){
        if(root == nullptr){
            return;
        }

        target -= root -> val;
        temp.push_back(root -> val);

        if(target == 0 && root -> left == nullptr && root -> right == nullptr){
            ans.push_back(temp);
        } else{
            fun(root -> left, target, temp, ans);
            fun(root -> right, target, temp, ans);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(root, targetSum, temp, ans);
        return ans;
    }
};
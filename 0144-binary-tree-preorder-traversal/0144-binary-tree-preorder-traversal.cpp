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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.reserve(200);
        if(!root){
            return ans;
        }

        stack<TreeNode*> s;
        
        while(!s.empty() || root){
            if(root){
                s.push(root);
                ans.push_back(root -> val);
                root = root -> left;
            } else{
                root = s.top(); s.pop();
                root = root -> right;
            }
        }

        return ans;
    }
};
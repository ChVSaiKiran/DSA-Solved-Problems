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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.reserve(200);
        if(!root){
            return ans;
        }
        
        stack<TreeNode*> s; s.push(root);
        while(!s.empty()){
            root = s.top(); s.pop();
            if(root -> right)
                s.push(root -> right);

            if(root -> left == nullptr && root -> right == nullptr){
                ans.push_back(root -> val);
            } else{
                s.push(root);
            }

            if(root -> left)
                s.push(root -> left);
            
            root -> left = root -> right = nullptr;
        }

        return ans;        
    }
};
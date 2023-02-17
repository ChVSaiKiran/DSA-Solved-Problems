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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> inorder;
        while(true){
            if(root){
                s.push(root);
                root = root -> left;
            }
            else{
                if(s.empty())
                    break;
                root = s.top();
                s.pop();
                inorder.emplace_back(root -> val);
                root = root -> right;
            }
        }
        int mini = INT_MAX;
        for(int i = 1; i < inorder.size(); i++)
            mini = min(mini , inorder[i] - inorder[i - 1]);
        return mini;
    }
};
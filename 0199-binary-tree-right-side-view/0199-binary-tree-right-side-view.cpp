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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root){
            return rightView;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size(), last;
            for(int i = 1; i <= n; i++){
                root = q.front(); q.pop();
                if(root -> left)    q.push(root -> left);
                if(root -> right)   q.push(root -> right);
                last = root -> val;
            }
            rightView.push_back(last);
        }

        return rightView;
    }
};
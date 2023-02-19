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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        bool flag = false;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++){
                TreeNode *x = q.front();
                temp[i] = x -> val;
                q.pop();
                if(x -> left)   q.push(x -> left);
                if(x -> right)  q.push(x -> right);
            }
            
            if(flag)
                reverse(temp.begin(),temp.end());
            
            ans.emplace_back(temp);
            flag = !flag;
        }
        
        return ans;
    }
};
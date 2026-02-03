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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            map<int, multiset<int>> lvl;
            for(int i = 0; i < n; i++){
                TreeNode* root = q.front().first;
                int l = q.front().second;
                q.pop();

                lvl[l].insert(root -> val);
                if(root -> left){
                    q.push({root -> left, l - 1});
                }

                if(root -> right){
                    q.push({root -> right, l + 1});
                }
            }

            for(auto it : lvl){
                mp[it.first].insert(mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void f(TreeNode* root, map<int, TreeNode*> &mp, TreeNode *par){
        if(!root)   return;
        mp[root -> val] = par;
        f(root -> left, mp, root);
        f(root -> right, mp, root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, TreeNode*> mp;
        f(root, mp, nullptr);

        queue<TreeNode*> q; 
        q.push(target);

        int lvl = 0;
        vector<int> ans;
        unordered_set<int> st;  st.insert(target -> val);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                root = q.front();   q.pop();
                if(root -> left && !st.contains(root -> left -> val)){
                    q.push(root -> left);   st.insert(root -> left -> val);
                }

                if(root -> right && !st.contains(root -> right -> val)){
                    q.push(root -> right);  st.insert(root -> right -> val);
                }

                TreeNode* temp = mp[root -> val];
                if(temp != nullptr && !st.contains(temp -> val)){
                    q.push(temp);           st.insert(temp -> val);
                }

                if(lvl == k){
                    ans.push_back(root -> val);
                }
            }

            lvl ++;
        }

        return ans;
    }
};
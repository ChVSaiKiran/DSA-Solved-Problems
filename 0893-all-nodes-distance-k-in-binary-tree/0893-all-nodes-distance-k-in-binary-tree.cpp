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
    vector<int> ans;
    unordered_map<int, pair<int, TreeNode*>> mp;
    int f(TreeNode* root, TreeNode* target, int k){
        if(root == nullptr){
            return 0;
        }

        if(root == target){
            return 1;
        } else{
            int lt = f(root -> left, target, k);
            int rt = f(root -> right, target, k);
            int val = 0;
            if(lt >= 1 && lt < k){
                val = lt + 1;
                mp[lt] = make_pair(1, root);
            } else if(lt == k){
                val = lt + 1;
                ans.push_back(root -> val);
            } else if(rt >= 1 && rt < k){
                val = rt + 1;
                mp[rt] = make_pair(2, root);
            } else if(rt == k){
                val = rt + 1;
                ans.push_back(root -> val);
            }

            return val;
        }
    }

    void fun(TreeNode* root, int k, int dis){
        if(root == nullptr || dis > k){
            return;
        }

        if(dis == k){
            ans.push_back(root -> val);
        } else{
            fun(root -> left, k, dis + 1);
            fun(root -> right, k, dis + 1);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            ans.push_back(target -> val);
            return ans;
        }

        f(root, target, k);
        fun(target -> left, k, 1);
        fun(target -> right, k, 1);
        for(int dis = 1; dis < k; dis++){
            if(mp.find(dis) != mp.end()){
                auto it = mp[dis];
                TreeNode *node = it.first == 1 ? it.second -> right : it.second -> left;
                fun(node, k, dis + 1);
            }
        }
        return ans;                 
    }
};
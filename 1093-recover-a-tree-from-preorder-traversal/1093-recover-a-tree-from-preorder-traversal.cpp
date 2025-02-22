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
    void fun(TreeNode *root, vector<pair<int,int>> &temp, int d, int &idx){
        if(idx < temp.size() && temp[idx].second == d + 1){
            root -> left = new TreeNode(temp[idx++].first);
            fun(root -> left, temp, d + 1, idx);
        }
        
        if(idx < temp.size() && temp[idx].second == d + 1){
            root -> right = new TreeNode(temp[idx++].first);
            fun(root -> right, temp, d + 1, idx);
        }
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> temp;
        int cnt = 0, i = 0, n = traversal.size();
        char prev = '-';
        while(i < n){
            if(traversal[i] == '-'){
                cnt++; i++; continue;
            }
            
            int val = 0;
            while(i < n && isdigit(traversal[i])){
                val = (val * 10) + (traversal[i++] - '0');
            }

            temp.push_back({val, cnt});
            cnt = 0;
        }

        TreeNode *root = new TreeNode(temp[0].first);
        int idx = 1;
        fun(root, temp, 0, idx);
        return root;
    }
};
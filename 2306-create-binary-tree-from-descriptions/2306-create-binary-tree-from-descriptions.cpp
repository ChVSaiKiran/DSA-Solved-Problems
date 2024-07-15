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
private :
    unordered_map<int, TreeNode*> mp;
    void fun(vector<vector<int>>& arr, int i){
        int parentVal = arr[i][0], childVal = arr[i][1], isLeft = arr[i][2];
        TreeNode *par, *child;

        if(mp.find(parentVal) != mp.end()){
            par = mp[parentVal];
        } else{
            par = new TreeNode(parentVal);
            mp[parentVal] = par;
        }

        if(mp.find(childVal) != mp.end()){
            child = mp[childVal];
        } else{
            child = new TreeNode(childVal);
            mp[childVal] = child;
        }

        if (isLeft == 1){
            par -> left = child;
        } else{
            par -> right = child;
        }

        if(i == 0){
            return;
        }
        fun(arr, i - 1);
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        fun(descriptions, descriptions.size() - 1);
        for (const auto& desc : descriptions) {
            mp.erase(desc[1]);
        }
        for(auto it : mp)
           return it.second;
        return nullptr;
    }
};
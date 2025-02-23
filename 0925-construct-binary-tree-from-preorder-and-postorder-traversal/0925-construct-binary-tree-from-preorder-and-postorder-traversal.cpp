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
    TreeNode* f(vector<int>& preorder, int &preIdx, unordered_map<int, int> &postorder, int prevIdx){
        if(preIdx >= preorder.size()){
            return nullptr;
        }

        int postIdx = postorder[preorder[preIdx]];
        if(postIdx > prevIdx){
            return nullptr;
        }
        
        return new TreeNode(preorder[preIdx++], f(preorder, preIdx, postorder, postIdx), f(preorder, preIdx, postorder, postIdx));
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < postorder.size(); i++){
            mp[postorder[i]] = i;
        }
        int postIdx = 0;
        return f(preorder, postIdx, mp, postorder.size());
    }
};
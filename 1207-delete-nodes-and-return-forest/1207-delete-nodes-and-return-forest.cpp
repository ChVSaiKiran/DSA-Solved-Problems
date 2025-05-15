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
    TreeNode* fun(TreeNode *root, unordered_set<int> &toDelete, vector<TreeNode*> &ans){
        if(root == nullptr){
            return root;
        }

        TreeNode* lt = fun(root -> left, toDelete, ans);
        TreeNode* rt = fun(root -> right, toDelete, ans);

        if(toDelete.find(root -> val) != toDelete.end()){
            root = nullptr;
            if(lt)  ans.push_back(lt);
            if(rt)  ans.push_back(rt);    
        } else{
            root -> left = lt;  root -> right = rt;
        }

        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        TreeNode *res = fun(root, toDelete, ans);
        if(res)    ans.push_back(res);
        return ans;
    }
};
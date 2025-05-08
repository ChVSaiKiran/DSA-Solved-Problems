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
    bool isLeaf(TreeNode *root){
        return !root -> left && !root -> right;
    }

    void fun(TreeNode* root, string &path, string &ans, bool isRoot){
        if(root == nullptr) return;

        path += ('a' + root -> val);
        if(isLeaf(root)){
            if(!isRoot){
                string temp(path.rbegin(), path.rend());
                ans = min(ans, temp);   
            }
        } else{
            fun(root -> left, path, ans, false);
            fun(root -> right, path, ans, false);
        }
        path.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "{", path;
        fun(root, path, ans, true);
        if(ans == "{") ans = ('a' + root -> val);
        return ans;
    }
};
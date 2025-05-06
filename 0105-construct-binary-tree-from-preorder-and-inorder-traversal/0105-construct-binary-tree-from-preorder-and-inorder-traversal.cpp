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
    TreeNode* fun(int &idx, int l, int r, vector<int>& preorder, vector<int>& inorder){
        if(l > r)   return nullptr;
        
        int pos = -1;
        for(int i = l; i <= r; i++){
            if(preorder[idx] == inorder[i]){
                pos = i;    break;
            }
        }

        if(pos == -1)   return nullptr;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root -> left = fun(idx, l, pos - 1, preorder, inorder);
        root -> right = fun(idx, pos + 1, r, preorder, inorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return fun(idx, 0, preorder.size() - 1, preorder, inorder);
    }
};
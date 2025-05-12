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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }

        bool found = root -> val == p -> val || root -> val == q -> val;
        if(found){
            return root;
        }

        TreeNode* lt = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rt = lowestCommonAncestor(root -> right, p, q);
        return (lt && rt) ? root : max(lt, rt);
    }
};
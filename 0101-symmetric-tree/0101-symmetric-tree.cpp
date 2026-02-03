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
    bool f(TreeNode* lt, TreeNode* rt){
        if((!lt && rt) || (lt && !rt)){
            return false;
        }
        return (!lt && !rt) || ((lt -> val == rt -> val) && f(lt -> left, rt -> right) && f(lt -> right, rt -> left));
    }

    bool isSymmetric(TreeNode* root) {
        return f(root -> left, root -> right);
    }
};
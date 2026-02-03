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
    int fun(TreeNode* root){
        if(!root){
            return 0;
        }

        int lt = fun(root -> left);
        int rt = fun(root -> right);

        if(lt == -1 || rt == -1 || abs(lt - rt) > 1){
            return -1;
        }

        return max(lt, rt) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return fun(root) != -1;
    }
};
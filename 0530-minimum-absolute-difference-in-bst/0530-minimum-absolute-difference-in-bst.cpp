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
    TreeNode* getInorderPredecessor(TreeNode* root){
        TreeNode* node = root -> left;
        while(node -> right){
            node = node -> right;
        }
        return node;
    }

    TreeNode* getInorderSuccessor(TreeNode* root){
        TreeNode* node = root -> right;
        while(node -> left){
            node = node -> left;
        }
        return node;
    }

    void fun(TreeNode* root, int &diff){
        if(root -> left == nullptr && root -> right == nullptr){
            return;
        }

        if(root -> left){
            TreeNode* node = getInorderPredecessor(root);
            diff = min(diff, abs(node -> val - root -> val));
            fun(root -> left, diff);
        }

        if(root -> right){
            TreeNode* node = getInorderSuccessor(root);
            diff = min(diff, abs(node -> val - root -> val));
            fun(root -> right, diff);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        fun(root, diff);
        return diff;
    }
};
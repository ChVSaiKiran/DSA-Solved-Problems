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
    TreeNode *ans;
    int fun(TreeNode *root, int lvl, int &maxLvl){
        if(!root){
            return lvl;
        }

        int lt = fun(root -> left, lvl + 1, maxLvl);
        int rt = fun(root -> right, lvl + 1, maxLvl);

        if(lt == rt && (lt >= maxLvl || rt >= maxLvl)){
            ans = root;
            if(lt > maxLvl){
                maxLvl = lt;
            }
        }

        return max(lt, rt);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int lvl = 0, maxLvl = 0;
        fun(root, lvl, maxLvl);
        return ans;
    }
};
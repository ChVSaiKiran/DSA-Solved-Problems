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
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode *ans = root;
        queue<TreeNode*> q;
        q.push(root);
        root -> val = 0;

        while(!q.empty()){
            int n = q.size(), sum = 0;
            queue<TreeNode*> level;
            while(n--){
                root = q.front(); q.pop();
                if(root -> left){
                    q.push(root -> left);
                    sum += root -> left -> val;
                }
                if(root -> right){
                    q.push(root -> right);
                    sum += root -> right -> val;
                }
                level.push(root);
            }

            while(!level.empty()){
                TreeNode *temp = level.front(); level.pop();
                int val = sum;
                if(temp -> left){
                    val -= temp -> left -> val;
                }
                
                if(temp -> right){
                    val -= temp -> right -> val;
                }

                if(temp -> left){
                    temp -> left -> val = val;
                }

                if(temp -> right){
                    temp -> right -> val = val;
                }
            }
        }

        return ans;
    }
};
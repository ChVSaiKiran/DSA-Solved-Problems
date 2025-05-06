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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0, maxSum = INT_MIN, lvl = 0;
        while(!q.empty()){
            int n = q.size(), sum = 0;  lvl++;
            for(int i = 1; i <= n; i++){
                root = q.front(); q.pop();
                if(root -> left)    q.push(root -> left);
                if(root -> right)   q.push(root -> right);
                sum += root -> val;
            }
            if(maxSum < sum){
                ans = lvl;  maxSum = sum;
            }
        }

        return ans;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long>> q;  q.push({root, 1});

        while(!q.empty()){
            int n = q.size();   long minVal = q.front().second;
            for(int i = 0; i < n; i++){
                root = q.front().first; long idx = q.front().second;   q.pop();
                if(root -> left){
                    q.push({root -> left, 2 * idx - minVal});
                }

                if(root -> right){
                    q.push({root -> right, 2 * idx - minVal + 1});
                }

                ans = max(ans, (int)(idx - minVal + 1));
            }
        }

        return ans;
    }
};
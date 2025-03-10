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
        queue<pair<long, TreeNode*>> q({{0, root}});
        while(!q.empty()){
            long n = q.size(), minVal = LONG_MAX, maxVal = 0, mmin = q.front().first;
            while(n--){
                long val = q.front().first - mmin;
                TreeNode *curr = q.front().second;
                q.pop();
                minVal = min(minVal, val);
                maxVal = max(maxVal, val);
                if(curr -> left)    q.push({2 * val + 1, curr -> left});
                if(curr -> right)   q.push({2 * val + 2, curr -> right});
            }
            ans = max(ans, static_cast<int>(maxVal - minVal + 1));
        }
        return ans;
    }
};
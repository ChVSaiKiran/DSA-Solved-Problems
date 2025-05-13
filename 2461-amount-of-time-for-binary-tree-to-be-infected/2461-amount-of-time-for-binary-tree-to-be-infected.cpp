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
    int f(TreeNode* root, int start, int &maxTime){
        int depth = 0;
        if(root == nullptr){
            return depth;
        }

        int lt = f(root -> left, start, maxTime);
        int rt = f(root -> right, start, maxTime);

        if(root -> val == start){
            depth = -1;
            maxTime = max(maxTime, max(lt, rt));
        } else if(lt >= 0 && rt >= 0){
            depth = max(lt, rt) + 1;
        } else{
            depth = min(lt, rt) - 1;
            maxTime = max(maxTime, abs(lt) + abs(rt));
        }
        
        return depth;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int maxTime = 0;
        f(root, start, maxTime);
        return maxTime;
    }
};
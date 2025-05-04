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
    TreeNode* cloneDeep(TreeNode *root){
        if(root == nullptr){
            return nullptr;
        }
        return new TreeNode(root -> val, cloneDeep(root -> left), cloneDeep(root -> right));
    }

    TreeNode* getNewCurrNode(TreeNode *root, int val){
        if(root -> val == val){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            root = q.front();   q.pop();
            if(root -> left){
                if(root -> left -> val == val){
                    return root -> left;
                }
                q.push(root -> left);                
            }
            if(root -> right){
                if(root -> right -> val == val){
                    return root -> right;
                }
                q.push(root -> right);
            }
        }

        return nullptr;
    }

    void fun(TreeNode *root, TreeNode *curr, vector<TreeNode*> &arr, int val){
        if(curr == nullptr){
            return;
        }

        fun(root, curr -> right, arr, val);

        TreeNode *newRoot = cloneDeep(root);
        TreeNode *newCurr = getNewCurrNode(newRoot, curr -> val);
        TreeNode *newNode = new TreeNode(val, nullptr, nullptr);
        newNode -> left = newCurr -> right;
        newCurr -> right = newNode;

        arr.push_back(newRoot);
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans(1, new TreeNode(1));
        for(int val = 2; val <= n; val++){
            vector<TreeNode*> newTrees;
            for(auto it : ans){
                fun(it, it, newTrees, val);
                newTrees.push_back(new TreeNode(val, cloneDeep(it), nullptr));
            }
            ans = newTrees;
        }
        return ans;
    }
};
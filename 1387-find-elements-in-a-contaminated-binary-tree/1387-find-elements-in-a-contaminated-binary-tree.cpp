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
class FindElements {
private:
    unordered_set<int> st;
    void fun(TreeNode *root, int curr){
        if(root -> left != nullptr){
            int left = 2 * curr + 1;
            st.insert(left);
            fun(root -> left, left);
        }

        if(root -> right != nullptr){
            int right = 2 * curr + 2;
            st.insert(right);
            fun(root -> right, right);
        }
    }

public:
    FindElements(TreeNode* root) {
        st.insert(0);
        fun(root, 0);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
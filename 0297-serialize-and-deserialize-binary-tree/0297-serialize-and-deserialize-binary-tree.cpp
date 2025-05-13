/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root == nullptr){
            return ans;
        }

        ans = to_string(root -> val);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            string lvl;

            for(int i = 0; i < n; i++){
                root = q.front();   q.pop();
                if(root -> left){
                    lvl += "," + to_string(root -> left -> val);
                    q.push(root -> left);
                } else{
                    lvl += ",*"; 
                }

                if(root -> right){
                    lvl += "," + to_string(root -> right -> val);
                    q.push(root -> right);
                } else{
                    lvl += ",*"; 
                }
            }

            ans += lvl;
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return nullptr;
        }

        TreeNode* root;
        queue<TreeNode*> q;
        stringstream ss(data);

        if(ss.good()){
            string val; getline(ss, val, ',');
            root = new TreeNode(stoi(val));
            q.push(root);
        }

        while(ss.good()){
            string val1; getline(ss, val1, ',');
            string val2; getline(ss, val2, ',');

            TreeNode *lt = (val1 == "*") ? nullptr : new TreeNode(stoi(val1));
            TreeNode *rt = (val2 == "*") ? nullptr : new TreeNode(stoi(val2));

            TreeNode *temp = q.front(); q.pop();
            temp -> left = lt;  temp -> right = rt;
            if(lt != nullptr)   q.push(lt);
            if(rt != nullptr)   q.push(rt);
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
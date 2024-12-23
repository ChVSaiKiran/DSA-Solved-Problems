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
    int fun(vector<int> adj[], int u, vector<bool> &vis){
        vis[u] = true;
        int cnt = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                cnt += fun(adj, v, vis);
            }
        }
        return cnt;
    }

    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> temp;
        temp.reserve(n);
        
        for(int i = 0; i < n; i++){
            temp.push_back({arr[i], i});
        }
        
        sort(temp.begin(), temp.end());

        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            int org = temp[i][1];
            adj[org].push_back(i);
        }
        
        int swaps = 0;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                swaps += (fun(adj, i, vis) - 1);
            }
        }
        
        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            arr.reserve(n);

            for(int i = 0; i < n; i++){
                TreeNode *temp = q.front();
                q.pop();

                arr.push_back(temp -> val);
                if(temp -> left)    q.push(temp -> left);
                if(temp -> right)   q.push(temp -> right);
            }

            ans += minSwaps(arr);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> ind(n, 0);
        for(auto it : prerequisites){
            ind[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int u = q.front();  q.pop();
            ans.push_back(u);

            for(int v : adj[u]){
                ind[v]--;
                if(ind[v] == 0){
                    q.push(v);
                }
            }
        }

        if(ans.size() != n) ans.clear();

        return ans;
    }
};
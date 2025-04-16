class Solution {
private:
    int len = 0;
    bool fun(vector<int> adj[], int u, int bob, int cnt, vector<int>& amount, vector<bool> &vis){
        vis[u] = true;

        if(u == bob){
            len = cnt;
            amount[u] = 0;
            vis[u] = false;
            return true;
        }

        bool flag = false;
        for(int v : adj[u]){
            if(!vis[v])
                flag = fun(adj, v, bob, cnt + 1, amount, vis) || flag;
        }

        if(flag){
            if(len / 2 < cnt){
                amount[u] = 0;
            } else if(len % 2 == 0 && len / 2 == cnt){
                amount[u] /= 2;
            }
        }

        vis[u] = false;
        return flag;
    }

    int getMostProfitPath(int u, vector<int> adj[], vector<int>& amount, vector<bool> &vis){
        vis[u] = true;
        int val = INT_MIN;
        
        for(int v : adj[u]){
            if(!vis[v])
                val = max(val, getMostProfitPath(v, adj, amount, vis));
        }

        return amount[u] + (val == INT_MIN ? 0 : val);
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        vector<bool> vis(n, false);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        fun(adj, 0, bob, 0, amount, vis);
        
        return getMostProfitPath(0, adj, amount, vis);
    }


};
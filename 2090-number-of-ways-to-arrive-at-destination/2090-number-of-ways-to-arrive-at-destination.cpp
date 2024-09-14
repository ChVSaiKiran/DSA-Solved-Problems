class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int MOD = 1e9 + 7;
        vector<long long> dis(n, LLONG_MAX), paths(n, 0);
        set<pair<long long,int>> st;
        st.insert({0, 0});
        dis[0] = 0;
        paths[0] = 1;

        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);

            long long disU = it.first;
            int u = it.second;
            
            for(pair<int,int> p : adj[u]){
                int v = p.first, edgW = p.second;
                if(dis[v] > disU + edgW){
                    paths[v] = paths[u];
                    dis[v] = disU + edgW;
                    st.insert({dis[v], v}); 
                } else if(dis[v] == disU + edgW){
                    paths[v] = (paths[u] + paths[v]) % MOD;
                    st.insert({dis[v], v}); 
                } 
            }
        }

        return paths[n - 1];
    }
};
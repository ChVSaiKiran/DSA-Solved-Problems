class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dis(n + 1, 1e9);
        set<pair<int,int>> st;
        st.insert({0, k});
        dis[k] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);

            int disU = it.first;
            int u = it.second;
            
            for(pair<int,int> p : adj[u]){
                int v = p.first, edgW = p.second;
                if(dis[v] > disU + edgW){
                    if(dis[v] != 1e9){
                        st.erase({dis[v], v});
                    }
                    
                    dis[v] = disU + edgW;
                    st.insert({dis[v], v}); 
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == 1e9){
                return -1;
            }
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            int u = it[0], v = it[1], edgW = it[2];
            adj[u].push_back(pair(v, edgW));
        }

        vector<int> dis(n, 1e9);
        set<pair<int, pair<int, int>>> st;
        st.insert({-1, {0, src}});    dis[src] = 0;

        while(!st.empty()){
            int stops = (*st.begin()).first;  
            int val = (*st.begin()).second.first;
            int u = (*st.begin()).second.second; 
            st.erase(st.begin());

            if(stops >= k){
                continue;
            }

            for(auto it : adj[u]){
                int v = it.first, edgW = it.second;
                if(dis[v] > val + edgW){
                    dis[v] = val + edgW;    st.insert({stops + 1, {dis[v], v}});
                }
            }
        }

        if(dis[dst] == 1e9){
            return -1;
        }

        return dis[dst];
    }
};
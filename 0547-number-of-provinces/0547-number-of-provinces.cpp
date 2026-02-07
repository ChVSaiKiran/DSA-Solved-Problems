class DisJoint {
public:
    vector<int> rank, parent;
    DisJoint(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findPar(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

    void unionFind(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v)  return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJoint ds = DisJoint(n);
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(isConnected[u][v] == 1 && u != v){
                    ds.unionFind(u, v);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds.findPar(i) == i){
                cnt++;
            }
        }

        return cnt;
    }
};
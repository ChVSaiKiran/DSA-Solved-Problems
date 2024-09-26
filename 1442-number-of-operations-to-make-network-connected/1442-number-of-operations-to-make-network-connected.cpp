struct DisjointSet{
private:
    vector<int> par, rnk;
public:
    DisjointSet(int n){
        par.resize(n + 1);
        rnk.resize(n + 1, 1);
        for(int i = 0; i <= n; i++){
            par[i] = i;
        }
    }

    int getParent(int node){
        if(node == par[node]){
            return node;
        }
        return par[node] = getParent(par[node]);
    }

    void unionByRank(int u, int v){
        int pu = getParent(u);
        int pv = getParent(v);

        if(pu == pv){
            return;
        }

        if(rnk[pu] < rnk[pv]){
            par[pu] = pv;
        } else if(rnk[pv] < rnk[pu]){
            par[pv] = pu;
        } else{
            par[pv] = pu;
            rnk[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noOfEdges = connections.size();
        if(noOfEdges < n - 1){
            return -1;
        }

        DisjointSet obj(n);
        for(auto it : connections){
            obj.unionByRank(it[0], it[1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(obj.getParent(i) == i){
                ans++;
            }
        }

        return ans - 1;
    }
};
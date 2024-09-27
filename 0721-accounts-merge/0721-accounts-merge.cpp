struct DisjointSet{
public:
    vector<int> par, rnk;
    DisjointSet(int n){
        par.resize(n + 1);
        rnk.resize(n + 1, 0);
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
        } if(rnk[pu] < rnk[pv]){
            par[pu] = pv;
        } else{
            par[pv] = pu;
            rnk[pu] += (rnk[pu] == rnk[pv]);
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet obj(n);
        map<string, int> mp;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    obj.unionByRank(mp[accounts[i][j]], i);
                } else{
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> ans;
        unordered_map<int,int> temp;

        for(int i = 0; i < n; i++){
            if(obj.par[i] == i){
                temp[i] = ans.size();
                ans.push_back({accounts[i][0]});
            }
        }

        for(auto &it : mp){
            string s = it.first;
            int parIdx = obj.getParent(it.second);
            int ansIdx = temp[parIdx];
            ans[ansIdx].push_back(s); 
        }

        return ans;
    }
};
class DisJointSet{
    private int[] rank;
    private int[] par;

    public DisJointSet(int n){
        rank = new int[n + 1];
        par = new int[n + 1];

        for(int i = 1; i <= n; i++){
            rank[i] = 0;
            par[i] = i;
        }
    }

    public int findPar(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = findPar(par[u]);
    }

    public void unionByRank(int u, int v){
        int pU = findPar(u);
        int pV = findPar(v);
        if (pU == pV) return;

        if(rank[pU] > rank[pV]){
            par[pV] = pU;
        } else if(rank[pU] < rank[pV]){
            par[pU] = pV;
        } else{
            par[pU] = pV;
            rank[pV]++;
        }
    }
}

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int ans[] = null;
        DisJointSet ds = new DisJointSet(n);

        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            int pU = ds.findPar(u);
            int pV = ds.findPar(v);

            if(pU == pV){
                ans = edges[i];
            }
            ds.unionByRank(u, v);
        }
        return ans;
    }
}
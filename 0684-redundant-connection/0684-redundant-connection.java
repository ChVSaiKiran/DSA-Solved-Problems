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

    public boolean unionByRank(int u, int v){
        int pU = findPar(u);
        int pV = findPar(v);
        if (pU == pV) return true;

        if(rank[pU] > rank[pV]){
            par[pV] = pU;
        } else if(rank[pU] < rank[pV]){
            par[pU] = pV;
        } else{
            par[pU] = pV;
            rank[pV]++;
        }

        return false;
    }
}

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        DisJointSet ds = new DisJointSet(edges.length);
        return Arrays.stream(edges).filter(edge -> ds.unionByRank(edge[0], edge[1])).findFirst().orElse(null);

    }
}
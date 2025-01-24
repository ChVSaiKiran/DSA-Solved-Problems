class Solution {
    private int f(int[][] graph, int u, int vis[]){
        if(vis[u] != 0){
            return vis[u];
        }

        vis[u] = 1;
        for(int v : graph[u]){
            if(f(graph, v, vis) == 1){
                return vis[u];
            }
        }

        return vis[u] = 2;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int vis[] = new int[n];
        
        for(int u = 0; u < n; u++){
            f(graph, u, vis);
        }

        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(vis[i] == 2){
                ans.add(i);
            }
        }

        return ans;
    }
}
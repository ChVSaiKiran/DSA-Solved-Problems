//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int V, int u, vector<int> adj[], vector<bool> &NotVisited, vector<int> &Parent){
        NotVisited[u] = false;
        for(int v:adj[u]){
            if(NotVisited[v]){
                Parent[v] = u;
                if(dfs(V, v, adj, NotVisited, Parent))
                    return true;
            }
            else if(Parent[u] != v && Parent[v] != u)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> NotVisited(V, true);
        vector<int> Parent(V, -1);
        for(int i = 0; i < V; i++)
            if(NotVisited[i])
                if(dfs(V, i, adj, NotVisited, Parent))
                    return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
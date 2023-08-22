//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(vector<int> adj[], vector<int> &vis, int u){
        vis[u] = 2;
        for(int v: adj[u]){
            if(vis[v] == 0){
                if(dfs(adj, vis, v))
                    return true;
            }
            else if(vis[v] == 2)
                return true;
        }
        vis[u] = 1;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(vis[i] == 0)
                if(dfs(adj, vis, i))
                    return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
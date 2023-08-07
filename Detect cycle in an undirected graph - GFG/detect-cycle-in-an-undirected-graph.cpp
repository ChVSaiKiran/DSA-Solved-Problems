//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> NotVisited(V, true);
        vector<int> Parent(V, -1);
        queue<int> q;
        for(int i = 0; i < V; i++)
            if(NotVisited[i]){
                NotVisited[i] = true;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int v:adj[u]){
                        if(NotVisited[v]){
                            NotVisited[v] = false;
                            q.push(v);
                            Parent[v] = u;
                        }
                        else if(Parent[u] != v && Parent[v] != u)
                        	return true;
                    }
                }
            }
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
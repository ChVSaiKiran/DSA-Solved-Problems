//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int row, int col, int delrow[], int delcol[]){
        vis[row][col] = true;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(nrow > -1 && nrow < n && ncol > -1 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol])
                dfs(grid, vis, nrow, ncol, delrow, delcol);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < m; i++){
            if(!vis[0][i] && grid[0][i])
                dfs(grid, vis, 0, i, delrow, delcol);
            if(!vis[n - 1][i] && grid[n - 1][i])
                dfs(grid, vis, n - 1, i, delrow, delcol);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0])
                dfs(grid, vis, i, 0, delrow, delcol);
            if(!vis[i][m - 1] && grid[i][m - 1])
                dfs(grid, vis, i, m - 1, delrow, delcol);
        }
        int cnt = 0;
        for(int i = 1; i < n - 1; i++)
            for(int j = 1; j < m - 1; j++)
                if(grid[i][j] && !vis[i][j])
                    cnt++;
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
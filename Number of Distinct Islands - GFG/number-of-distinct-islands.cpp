//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int n, m, delrow[4] = {-1, 0, 1, 0}, delcol[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int row, int col, int x0, int y0, string &s){
        grid[row][col] = 2;
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i], ncol = col + delcol[i];
            if(nrow > -1 && ncol > -1 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                s += string(1,x0 - nrow) + string(1, y0 - ncol);
                dfs(grid, nrow, ncol, x0, y0, s);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size(), m = grid[0].size();
        unordered_set<string> myset;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1){
                    string s;
                    dfs(grid, i, j, i, j, s);
                    myset.insert(s);
                }
        return myset.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
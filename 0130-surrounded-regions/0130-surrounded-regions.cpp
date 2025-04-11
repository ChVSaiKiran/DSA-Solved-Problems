class Solution {
private:
    void dfs(int u, int v, vector<vector<char>>& board, vector<vector<int>> &vis){
        if(vis[u][v])   return;
        vis[u][v] = true;
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nx = u + delRow[i];
            int ny = v + delCol[i];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O')
                dfs(nx, ny, board, vis);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, false));
        
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                dfs(i, 0, board, vis);
            if(board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O')
                dfs(0, i, board, vis);
            if(board[n - 1][i] == 'O')
                dfs(n - 1, i, board, vis);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j]){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
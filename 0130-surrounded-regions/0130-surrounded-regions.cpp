class Solution {
private:
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};

    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis){
        if(vis[x][y])   return;

        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int dx = x + row[i];
            int dy = y + col[i];
            if(dx >= 0 && dy >= 0 && dx < board.size() && dy < board[0].size() && board[dx][dy] == 'O'){
                dfs(dx, dy, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }

            if(board[i][m - 1] == 'O'){
                dfs(i, m - 1, board, vis);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, vis);
            }

            if(board[n - 1][i] == 'O'){
                dfs(n - 1, i, board, vis);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j])   board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
class Solution {
private:
    vector<int> nRow = {0, 1, 0, -1};
    vector<int> nCol = {1, 0, -1, 0};

    void dfs(int x, int y, vector<vector<char>> &board){
        board[x][y] = 'V';
        for(int i = 0; i < 4; i++){
            int nx = x + nRow[i];
            int ny = y + nCol[i];
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O'){
                dfs(nx, ny, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                dfs(i, 0, board);
            if(board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O')
                dfs(0, i, board);
            if(board[n - 1][i] == 'O')
                dfs(n - 1, i, board);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'V'){
                    board[i][j] = 'O';
                } else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
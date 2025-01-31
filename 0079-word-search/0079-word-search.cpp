class Solution {
private:
    bool fun(vector<vector<char>>& board, string &word, int idx, int i, int j, vector<vector<bool>> &vis){
        if(idx == word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || board[i][j] != word[idx]){
            return false;
        }
        
        vis[i][j] = true;
        bool res = fun(board, word, idx + 1, i, j + 1, vis) || fun(board, word, idx + 1, i, j - 1, vis) ||
               fun(board, word, idx + 1, i + 1, j, vis) || fun(board, word, idx + 1, i - 1, j, vis);
        vis[i][j] = false;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                if(fun(board, word, 0, i, j, vis)){
                    return true;
                }
            }
        }

        return false;
    }
};
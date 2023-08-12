class Solution {
    private boolean isvalid(int n, int m, int nrow, int ncol){
        return nrow >= 0 && ncol >= 0 && nrow < n && ncol < m;
    }
    private boolean isBound(int n, int m, int nrow, int ncol){
        return nrow == 0 || ncol == 0 || nrow == n - 1 || ncol == m - 1;
    }
    public void solve(char[][] board) {
        int n = board.length, m = board[0].length;
        boolean vis[][] = new boolean[n][m];
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O' && !vis[i][j] && !isBound(n, m, i, j)){
                Queue<Pair<Integer, Integer>> q = new LinkedList<>();
                ArrayList<Pair<Integer, Integer>> temp = new ArrayList<>();
                Pair<Integer, Integer> comb = new Pair<>(i,j);
                q.add(comb);
                temp.add(comb);
                boolean flag = true;
                while(!q.isEmpty()){
                    int x = q.peek().getKey(), y = q.peek().getValue();
                    q.remove();
                    for(int k = 0; k < 4; k++){
                        int nrow = x + delrow[k];
                        int ncol = y + delcol[k];
                        if(isvalid(n,m,nrow,ncol) && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                            vis[nrow][ncol] = true;
                            if(isBound(n, m, nrow, ncol))
                                flag = false;
                            comb = new Pair<>(nrow,ncol);
                            q.add(comb);
                            temp.add(comb);
                        }
                    }
                }
                if(flag){
                    for(Pair<Integer, Integer> it: temp)
                        board[it.getKey()][it.getValue()] = 'X';
                }
            }
        }
    }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int FreshCnt = 0, cnt = 0;
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.add(new Pair(i,j));
                else if(grid[i][j] == 1)
                    FreshCnt++;
            }
        while(!q.isEmpty()){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int i = q.peek().getKey(), j = q.peek().getValue();
                q.remove();
                if(i + 1 < n && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    FreshCnt--;
                    q.add(new Pair(i + 1, j));
                }
                
                if(i - 1 >= 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    FreshCnt--;
                    q.add(new Pair(i - 1, j));
                }
                
                if(j + 1 < m && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    FreshCnt--;
                    q.add(new Pair(i, j + 1));
                }
                
                if(j - 1 >= 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    FreshCnt--;
                    q.add(new Pair(i, j - 1));
                }
            }
            if(!q.isEmpty())
                cnt++;
        }
        return FreshCnt == 0 ? cnt : -1;
    }
}
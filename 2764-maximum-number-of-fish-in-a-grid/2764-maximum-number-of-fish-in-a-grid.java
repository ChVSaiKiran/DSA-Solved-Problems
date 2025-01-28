class Solution {
    public int findMaxFish(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean vis[][] = new boolean[n][m];

        int ans = 0;
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0 && vis[i][j] == false){
                    int cnt = 0;
                    vis[i][j] = true;

                    Queue<Integer> q = new LinkedList<>();
                    q.add((i * m) + j);
                    while(!q.isEmpty()){
                        int idx = q.poll();
                        int x = idx / m;
                        int y = idx % m;
                        cnt += grid[x][y];
                        
                        for(int d = 0; d < 4; d++){
                            int nx = delRow[d] + x;
                            int ny = delCol[d] + y;
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                                && grid[nx][ny] > 0 && vis[nx][ny] == false){
                                q.add((nx * m) + ny);
                                vis[nx][ny] = true;
                            }
                        }
                    }
                    ans = Math.max(ans, cnt);
                }
            }
        }

        return ans;
    }
}
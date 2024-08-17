class Solution {
    private long f(int[][] points, int x, int y, long[][] dp){
        if(x == 0){
            // System.out.println("X: " + x + " Y: " + y + " R: " + (points[x][y]));
            return points[x][y];
        }

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        long temp = 0;
        for(int j = 0; j < points[0].length; j++){
            temp = Math.max(temp, f(points, x - 1, j, dp) - Math.abs(y - j));
        }
        // System.out.println("X: " + x + " Y: " + y + " R: " + (points[x][y] + temp));
        return dp[x][y] = points[x][y] + temp;
    }
    public long maxPoints(int[][] points) {
        int n = points.length, m = points[0].length;

        // Memoization Approach
        // long ans = 0, dp[][] = new long[n][m];
        // for(long[] row : dp) {
            // Arrays.fill(row, -1);
        // } 
        // for(int j = 0; j < m; j++){
        //     ans = Math.max(ans, f(points, n - 1, j, dp));
        // }
        // return ans;
        

        // Tabulation Approach
        // for(int j = 0; j < m; j++){
        //     dp[0][j] = points[0][j];
        // }
        // for(int x = 1; x < n; x++){
        //     for(int y = 0; y < m; y++){
        //         long temp = 0;
        //         for(int j = 0; j < points[0].length; j++){
        //             temp = Math.max(temp, dp[x - 1][j] - Math.abs(y - j));
        //         }
        //         dp[x][y] = points[x][y] + temp;
        //     }
        // }
        // return Arrays.stream(dp[n - 1]).max().orElse(0L);

        // Space Optimized Approach
        
        long prev[] = new long[m];
        for(int j = 0; j < m; j++){
            prev[j] = points[0][j];
        }

        for(int x = 1; x < n; x++){
            long curr[] = new long[m];
            for(int y = 0; y < m; y++){
                long temp = 0;
                for(int j = 0; j < m; j++){
                    temp = Math.max(temp, prev[j] - Math.abs(y - j));
                }
                curr[y] = temp + points[x][y];
            }
            prev = curr;
        }

        return Arrays.stream(prev).max().orElse(0L);
    }
}
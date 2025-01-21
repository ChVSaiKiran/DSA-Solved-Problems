class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        long prefSum = 0, ans = Long.MAX_VALUE;
        long suffSum[] = new long[n];

        for(int i = n - 2; i >= 0; i--){
            suffSum[i] = suffSum[i + 1] + grid[0][i + 1];
        }

        for(int i = 0; i < n; i++){
            ans = Math.min(ans, Math.max(prefSum, suffSum[i]));
            prefSum += grid[1][i];
        }

        return ans;
    }
}
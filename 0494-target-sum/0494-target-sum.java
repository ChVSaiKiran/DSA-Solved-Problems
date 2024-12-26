class Solution {
    private int fun(int[] nums, int sum, int i, int[][] dp){
        if(i == -1){
            return (sum == 0) ? 1 : 0;
        }

        int idx = sum + (int)2e4 + 1;
        if(dp[i][idx] != -1){
            return dp[i][idx];
        }

        int positive = fun(nums, sum + nums[i], i - 1, dp);
        int negitive = fun(nums, sum - nums[i], i - 1, dp);

        return (dp[i][idx] = positive + negitive);
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int dp[][] = new int[n][(int)1e5];

        for(int[] row : dp){
            Arrays.fill(row, -1);
        }

        return fun(nums, target, n - 1, dp);
    }
}
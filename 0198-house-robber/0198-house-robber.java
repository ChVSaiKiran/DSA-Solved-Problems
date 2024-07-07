class Solution {
    public int rob(int[] nums) {
        int n = nums.length, dp[] = new int[n];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = Math.max(dp[i - 1], nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0));
        }
        return dp[n - 1];
    }
}
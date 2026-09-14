class Solution {
    private int solve(int i, int val, int[] nums, int[][] dp){
        if(i >= nums.length || val < 0){
            return 0;
        }

        if(dp[i][val] != -1){
            return dp[i][val];
        }

        if(val == 0){
            return dp[i][val] = 1;
        }

        int notPick = solve(i + 1, val, nums, dp);
        int pick = solve(i + 1, val - nums[i], nums, dp);

        return dp[i][val] = pick + notPick > 0 ? 1 : 0;
    }

    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum(), val = sum / 2;
        if(sum % 2 == 1) return false;

        int[][] dp = new int[nums.length][val + 1];
        for(int[] row : dp){
            Arrays.fill(row, -1);
        }

        return solve(0, val, nums, dp) > 0;
    }
}
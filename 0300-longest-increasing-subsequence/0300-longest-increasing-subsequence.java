class Solution {
    private int f(int[] nums, int ind, int prev_ind, int dp[][]){
        if(ind - 1 == nums.length){
            return 0;
        }

        if(dp[ind][prev_ind] != -1){
            return dp[ind][prev_ind];
        }

        int notPick = f(nums, ind + 1, prev_ind, dp), pick = 0;

        if(prev_ind == 0 || nums[ind - 1] > nums[prev_ind - 1]){
            pick = 1 + f(nums, ind + 1, ind, dp);
        }

        return dp[ind][prev_ind] = Math.max(pick, notPick);
    }

    public int lengthOfLIS(int[] nums) {
        // Memoization Approach
        int n = nums.length;
        int dp[][] = new int[n + 1][n + 1];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }

        return f(nums, 1, 0, dp);
    }
}
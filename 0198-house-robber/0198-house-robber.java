class Solution {
    private int fun(int[] nums, int ind, int dp[]){
        if(ind < 0){
            return 0;
        } else if(ind == 0){
            return nums[0];
        } else if(dp[ind] != -1){
            return dp[ind];
        } else{
            int pick = nums[ind] + fun(nums, ind - 2, dp);
            int noPick = 0 + fun(nums, ind - 1, dp);
            return dp[ind] = Math.max(pick, noPick);
        }
    }

    public int rob(int[] nums) {
        int n = nums.length, dp[] = new int[n];
        for(int i = 0; i < n; i++)
            dp[i] = -1;
        return fun(nums, n - 1, dp);
    }
}
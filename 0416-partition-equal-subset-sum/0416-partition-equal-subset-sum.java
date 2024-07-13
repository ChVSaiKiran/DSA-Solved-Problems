class Solution {
    private int fun(int[] nums, int ind, int target, int dp[][]){
        if(target == 0){
            return dp[ind][target] = 1;
        }
        if(ind == 0){
            return dp[0][target] = (nums[0] == target ? 1 : 0);
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int notTake = fun(nums, ind - 1, target, dp), Take = 0;
        if(target >= nums[ind]){
            Take = fun(nums, ind - 1, target - nums[ind], dp);
        }
        return dp[ind][target] = notTake | Take;
    }
    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        if(sum % 2 == 1){
            return false;
        }
        int target = sum / 2, n = nums.length, dp[][] = new int[n][target + 1];
        // for()
        for(int row[] : dp){
            Arrays.fill(row, -1);
        }
        return fun(nums, n - 1, target, dp) == 1;
    }
}
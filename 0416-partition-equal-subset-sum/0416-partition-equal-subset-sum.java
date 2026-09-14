class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = Arrays.stream(nums).sum(), val = sum / 2;
        if(sum % 2 == 1) return false;

        int[] dp = new int[val + 1]; dp[0] = 1;

        for(int i = n - 1; i >= 0; i--){
            int[] curr = new int[val + 1]; curr[0] = 1;
            for(int j = 1; j <= val; j++){
                int notPick = dp[j], pick = (j - nums[i] >= 0) ? dp[j - nums[i]] : 0;
                curr[j] = (pick + notPick > 0) ? 1 : 0;
            }
            dp = curr;
        }

        return dp[val] > 0;
    }
}
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        if(sum % 2 == 1) return false;

        int val = sum / 2, n = nums.length;
        boolean[] dp = new boolean[val + 1]; dp[0] = true;

        for(int i = n - 1; i >= 0; i--){
            boolean[] curr = new boolean[val + 1]; curr[0] = true;
            for(int j = 1; j <= val; j++){
                boolean notPick = dp[j], pick = (j - nums[i] >= 0) ? dp[j - nums[i]] : false;
                curr[j] = pick || notPick;
            }
            dp = curr;
        }

        return dp[val];
    }
}
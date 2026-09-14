class Solution {
    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        if(sum % 2 == 1) return false;

        int val = sum / 2, n = nums.length;
        boolean[] dp = new boolean[val + 1]; dp[0] = true;

        for(int num : nums){
            for(int j = val; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[val];
    }
}
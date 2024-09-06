class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length, maxi = 1;

        int dp[] = new int[n];
        int cnts[] = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(cnts, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        maxi = Math.max(maxi, dp[i]);
                        cnts[i] = cnts[j];
                    } else if(dp[j] + 1 == dp[i]){
                        cnts[i] += cnts[j];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi)
                ans += cnts[i];
        }

        return ans;
    }
}
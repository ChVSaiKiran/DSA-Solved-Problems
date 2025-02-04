class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans  = 0, sum = 0, prev = Integer.MIN_VALUE;
        for(int i : nums){
            sum = i > prev ? sum + i : i;
            prev = i;
            ans = Math.max(sum, ans);
        }
        return ans;
    }
}
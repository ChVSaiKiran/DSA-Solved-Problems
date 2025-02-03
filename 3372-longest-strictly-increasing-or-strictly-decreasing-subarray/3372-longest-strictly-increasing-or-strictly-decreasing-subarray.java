class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length, len1 = 0, len2 = 0, ans = 0;
        int prevMax = Integer.MIN_VALUE, prevMin = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++){
            len1 = nums[i] > prevMax ? len1 + 1 : 1;
            len2 = nums[i] < prevMin ? len2 + 1 : 1;

            prevMax = nums[i];
            prevMin = nums[i];
            ans = Math.max(ans, Math.max(len1, len2));
        }

        return ans;
    }
}
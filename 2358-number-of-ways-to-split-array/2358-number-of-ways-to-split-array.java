class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length, cnt = 0;
        long sum = Arrays.stream(nums).asLongStream().sum(), left = 0;

        for(int i = 0; i < n - 1; i++){
            left += nums[i];
            long right = sum - left;
            cnt += (left >= right) ? 1 : 0;
        }

        return cnt;
    }
}
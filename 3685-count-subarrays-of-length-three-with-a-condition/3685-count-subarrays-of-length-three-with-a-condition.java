class Solution {
    public int countSubarrays(int[] nums) {
        int cnt = 0;
        for(int i = 1; i < nums.length - 1; i++){
            cnt += ((nums[i] == 2 * (nums[i - 1] + nums[i + 1])) ? 1 : 0);
        }
        return cnt;
    }
}
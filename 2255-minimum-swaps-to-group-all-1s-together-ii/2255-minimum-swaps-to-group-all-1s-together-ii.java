class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length, cnt = 0;
        for(int i : nums){
            cnt += (i == 1) ? 1 : 0;
        }
        int temp = 0, ans = Integer.MAX_VALUE;
        for(int i = 0; i < n + cnt; i++){
            if(i >= cnt){
                ans = Math.min(temp, ans);
                temp -= (nums[i - cnt] == 0) ? 1 : 0;
            }
            if(i < n){
                temp += (nums[i] == 0) ? 1 : 0;
            } else{
                temp += (nums[i - n] == 0) ? 1 : 0;
            }
            
        }
        return Math.min(ans, temp);
    }
}
class Solution {
    private int fun(int[] nums, int l, int r){
        if(l >= r)  return nums[0];
        int prev1 = nums[l];
        int prev2 = 0;
        for(int i = l + 1; i < r; i++){
            int pick = nums[i];
            if(i > l + 1)
                pick += prev2;
            int nonPick = 0 + prev1;
            prev2 = prev1;
            prev1 = Math.max(pick, nonPick);
        }
        return prev1;
    }
    public int rob(int[] nums) {
        int x = fun(nums, 0, nums.length - 1), y = fun(nums, 1, nums.length);
        return Math.max(x, y);
    }
}
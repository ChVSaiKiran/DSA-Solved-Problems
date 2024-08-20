class Solution {
    private int f(int[] nums, int target, boolean flag){
        int low = 0, high = nums.length - 1, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                if(flag){
                    high = mid - 1;
                } else{
                    low = mid + 1;
                }
            } else if(nums[mid] > target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        int ans[] = {f(nums, target, true), f(nums, target, false)};
        return ans;
    }
}
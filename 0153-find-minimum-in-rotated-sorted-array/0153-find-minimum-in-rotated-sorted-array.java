class Solution {
    public int findMin(int[] nums) {
        int low = 0, high = nums.length - 1, ans = Integer.MAX_VALUE;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < nums[high]){
                //Right Half is sorted & Nums[mid] would be smallest
                ans = Math.min(ans, nums[mid]);
                high = mid - 1;
            } else{
                // Left Half is sorted & Nums[low] would be smallest
                ans = Math.min(ans, nums[low]);
                low = mid + 1;
            }
        }
        return ans;
    }
}
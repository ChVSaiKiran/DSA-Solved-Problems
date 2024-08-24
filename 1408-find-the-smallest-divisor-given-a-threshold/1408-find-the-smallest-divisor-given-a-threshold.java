class Solution {
    private boolean f(int[] nums, int div, int threshold){
        int result = 0;
        for(int i : nums){
            result += Math.ceil((double)i / (double)div);
        }
        return result <= threshold;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1, ans = -1;
        int high = Arrays.stream(nums).max().getAsInt();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(f(nums, mid, threshold)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
}
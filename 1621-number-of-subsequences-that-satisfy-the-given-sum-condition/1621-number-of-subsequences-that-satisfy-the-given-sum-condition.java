class Solution {
    public int numSubseq(int[] nums, int target) {
        int n = nums.length, mod = (int)(1e9 + 7);
        long ans = 0;
        Arrays.sort(nums);

        long[] powerOf2 = new long[n];
        powerOf2[0] = 1;
        for (int i = 1; i < n; i++) {
            powerOf2[i] = (powerOf2[i - 1] * 2) % mod;
        }

        for(int i = 0; i < n; i++){
            int low = i, high = n - 1, idx = i - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[i] + nums[mid] <= target){
                    idx = mid;
                    low = mid + 1;
                } else{
                    high = mid - 1;
                }
            }
            
            if(idx >= i){
                ans = (ans + powerOf2[idx - i]) % mod;
            }
        }
        return (int)ans;
    }
}
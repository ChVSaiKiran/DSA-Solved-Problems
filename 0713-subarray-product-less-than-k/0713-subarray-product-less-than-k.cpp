class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size(), l = 0;
        long val = 1;
        for(int r = 0; r < n; r++){
            val *= nums[r];
            while(l <= r && val >= k){
                val /= nums[l++];
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};
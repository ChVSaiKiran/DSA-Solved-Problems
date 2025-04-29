class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long val = 1;
        int n = nums.size(), l = 0, cnt = 0;
        for(int r = 0; r < n; r++){
            val *= nums[r];
            while(val >= k && l <= r){
                val /= nums[l++];
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};
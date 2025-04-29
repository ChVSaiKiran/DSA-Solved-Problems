class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, minLen = INT_MAX, n = nums.size(), sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, r - l + 1);
                sum -= nums[l++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
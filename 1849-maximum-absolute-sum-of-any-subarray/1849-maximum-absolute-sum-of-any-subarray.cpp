class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int sum = 0, minVal = 0, maxVal = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, max(abs(sum - minVal), abs(sum - maxVal)));
            minVal = min(minVal, sum);
            maxVal = max(maxVal, sum);
        }

        return ans;
    }
};
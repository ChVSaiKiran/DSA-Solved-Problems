class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(1,nums[0]);
        for(int i = 1; i < nums.size();i++)
            ans.push_back(nums[i]+ans[i-1]);
        return ans;
    }
};
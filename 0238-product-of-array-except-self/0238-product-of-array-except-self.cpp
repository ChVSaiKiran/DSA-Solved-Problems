class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prefix = 1, sufix = 1;
        for(int i = 0; i < n; i++){
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[n - 1 - i] *= sufix;
            sufix *= nums[n - 1 - i];
        }
        return ans;
    }
};
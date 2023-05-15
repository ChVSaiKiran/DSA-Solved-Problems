class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> prefix, sufix(n,1);
        prefix.push_back(1);
        for(int i = 0; i < n; i++)
            prefix.push_back(prefix.back() * nums[i]);
        for(int i = n - 2; i >= 0; i--)
            sufix[i] = sufix[i + 1] * nums[i + 1];
        for(int i = 0; i < n; i++)
            ans.push_back(prefix[i] * sufix[i]);
        return ans;
    }
};
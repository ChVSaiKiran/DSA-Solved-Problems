class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int r = 0, n = nums.size(), res = 0;
        unordered_map<int, int> mp;     mp[0] = 1;

        for(int i = 0; i < n; i++){
            r = ((r + nums[i]) % k + k) % k;
            res += mp[r];   mp[r]++;
        }

        return res;
    }
};
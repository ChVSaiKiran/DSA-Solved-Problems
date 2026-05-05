class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, int> mp;

        long long cnt = 0;
        for(int i = 0; i < n; i++){
            int val = nums[i] - i;
            cnt += mp[val];
            mp[val]++;
        }

        long long res = n * (n - 1) / 2;
        return res - cnt;
    }
};
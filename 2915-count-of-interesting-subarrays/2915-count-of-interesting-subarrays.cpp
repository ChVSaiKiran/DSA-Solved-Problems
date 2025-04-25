class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        long long ans = 0, cnt = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            cnt += ((nums[i] % mod) == k);
            if(cnt % mod == k) ans++;

            // x - y = diff, I want diff % mod == k so
            // (x - y) % mod == k
            // (x % mod) - (y % mod) == k
            // (x % mod) - k = y % mod
            // Now we want LHS is present in the map or not
            // So, at the end we store the RHS in the map
            // LHS might be less that 0, so we will add mod & do % again with mod 
            int y = (((cnt % mod) - k) + mod) % mod;
            if(mp.find(y) != mp.end()){
                ans += mp[y];
            }
            mp[cnt % mod]++;
        }

        return ans;
    }
};
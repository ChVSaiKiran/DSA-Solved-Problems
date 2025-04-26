class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for(int i : nums){
            sum += i;
            if(sum == goal) ans++;
            if(mp.find(sum - goal) != mp.end()) ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};
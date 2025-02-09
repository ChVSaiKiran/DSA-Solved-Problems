class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;

        // j-i != nums[j] - nums[i]
        // can be writtern as nums[i] - i != nums[j] - j

        for(int i = 0; i < n; i++){
            int val = nums[i] - i; 
            ans += (i - mp[val]);
            mp[val]++;
        }
        
        return ans;
    }
};
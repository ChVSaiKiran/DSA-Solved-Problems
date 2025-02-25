class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int cnt = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += (nums[i] % 2);
            ans += mp[cnt - k];
            mp[cnt]++;
        }

        return ans;
    }
};
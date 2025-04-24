class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            unordered_map<int, int> temp;
            if(mp.size() == s.size()){
                ans++;
                for(int j = 0; j <= i; j++){
                    mp[nums[j]]--;  temp[nums[j]]++;
                    if(mp[nums[j]] < 1){
                        break;
                    }
                    ans++;  
                }
            }
            for(auto it : temp){
                mp[it.first] += it.second;
            }
        }

        return ans;
    }
};
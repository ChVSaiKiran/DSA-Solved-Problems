class Solution {
private:

public:
    int maxWidthRamp(vector<int>& nums) {
        map<int,int> mp{{nums[0], 0}};
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            auto it = mp.upper_bound(nums[i]);
            if(it != mp.begin()){
                ans = max(ans, i - prev(it) -> second);
                mp[nums[i]] = prev(it) -> second;
            } else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
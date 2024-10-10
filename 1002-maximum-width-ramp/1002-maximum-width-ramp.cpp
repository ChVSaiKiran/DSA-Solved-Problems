class Solution {
private:

public:
    int maxWidthRamp(vector<int>& nums) {
        map<int,int> mp{{nums[0], 0}};
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            int val = nums[i];
            auto it = mp.upper_bound(val);
            if(it != mp.begin()){
                int prevIdx = prev(it) -> second;
                ans = max(ans, i - prevIdx);
                if(mp.count(val)){
                    mp[val] = prevIdx;
                }
            } else{
                mp[val] = i;
            }
        }
        return ans;
    }
};
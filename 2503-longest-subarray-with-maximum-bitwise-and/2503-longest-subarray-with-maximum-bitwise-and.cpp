class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = nums[0], max_val = nums[0];
        int n = nums.size(), j = 0;
        unordered_map<int, int> mp{{val, 1}};

        for(int i = 0; i < n; i++){
            if((val & nums[i]) < nums[i]){
                val = nums[i];
                j = i;
            }
            val = val & nums[i];
            mp[val]  = max(mp[val], i - j + 1);
            max_val = max(max_val, val);
        }
        
        return mp[max_val];
    }
};
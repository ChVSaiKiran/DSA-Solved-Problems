class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = nums[0], max_val = nums[0];
        int n = nums.size(), j = 0;
        unordered_map<int, int> mp{{val, 1}};

        for(int i = 0; i < n; i++){
            int temp = val & nums[i];
            if(nums[i] > temp){
                val = nums[i];
                j = i;
            } else{
                val = temp;
            }
            max_val = max(max_val, val);
            mp[val]  = max(mp[val], i - j + 1);
        }

        return mp[max_val];
    }
};
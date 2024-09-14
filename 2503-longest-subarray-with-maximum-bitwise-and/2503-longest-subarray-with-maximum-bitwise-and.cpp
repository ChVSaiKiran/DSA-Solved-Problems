class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = nums[0], max_val = nums[0], max_val_len = 1;
        int n = nums.size(), j = 0;

        for(int i = 1; i < n; i++){
            int temp = val & nums[i];
            if(nums[i] > temp){
                val = nums[i], j = i;
            } else{
                val = temp;
            }

            int len = i - j + 1;

            if(val > max_val){
                max_val = val;
                max_val_len = 1;
            } else if(val == max_val){
                max_val_len = max(max_val_len, len);
            }
        }

        return max_val_len;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ones = 0, zeros = 0, l = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++){
            ones += (nums[r] == 1);
            zeros += (nums[r] == 0);
            while(zeros > 1){
                ones -= (nums[l] == 1);
                zeros -= (nums[l] == 0);    l++;
            }
            ans = max(ans, ones - (zeros == 0));
        }
        return ans;
    }
};
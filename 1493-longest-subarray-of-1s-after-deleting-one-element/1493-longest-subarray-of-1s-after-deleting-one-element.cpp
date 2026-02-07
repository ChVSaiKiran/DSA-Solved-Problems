class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, j = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt1 = cnt2;    cnt2 = 0;
            } else{
                cnt2++;
            }
            ans = max(ans, cnt1 + cnt2);
        }
        ans -= (ans == nums.size());
        return ans;
    }
};
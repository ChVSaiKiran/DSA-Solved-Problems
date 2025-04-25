class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), j = 0, ans = 0;
        for(int i = 0; i < n; i++){
            while(nums[i] == 0 && k == 0){
                k += (nums[j++] == 0);
            }
            k -= (nums[i] == 0);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
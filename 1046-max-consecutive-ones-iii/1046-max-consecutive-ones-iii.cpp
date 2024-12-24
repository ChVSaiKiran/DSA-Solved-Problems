class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), j = 0, ans = 0;
        for(int i = 0; i < n; i++){
            k -= (nums[i] == 0);
            while(k < 0 && (nums[j++] == 0)){
                k++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
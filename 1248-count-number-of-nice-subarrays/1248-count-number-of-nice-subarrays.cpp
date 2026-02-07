class Solution {
    int fun(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size(), j = 0, ans = 0;
        for(int i = 0; i < n; i++){
            cnt += (nums[i] % 2);
            while(cnt > k){
                cnt -= (nums[j++] % 2);
            }
            ans += (i - j + 1);
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};
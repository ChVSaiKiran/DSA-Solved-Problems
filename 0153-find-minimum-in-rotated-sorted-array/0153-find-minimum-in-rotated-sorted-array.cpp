class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = INT_MAX;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[l] <= nums[m]){  //left sorted
                ans = min(ans, nums[l]); l = m + 1;
            } else{
                ans = min(ans, nums[m]); r = m - 1;
            }
        }
        return ans;
    }
};
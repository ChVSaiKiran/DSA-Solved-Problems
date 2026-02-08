class Solution {
private:
    int f(vector<int>& nums, int target, bool flag){
        int n = nums.size(), l = 0, r = n - 1, ans = -1;
        while(l <= r){
            int m = (l + r)/2;
            if(nums[m] > target){
                r = m - 1;
            } else if(nums[m] < target){
                l = m + 1;
            } else if(flag){
                r = m - 1;  ans = m;
            } else{ 
                l = m + 1;  ans = m;
            }
        }

        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums, target, true), f(nums, target, false)};
    }
};
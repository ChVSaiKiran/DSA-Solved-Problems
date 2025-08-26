class Solution {
private:
    int f(vector<int> &nums, int target, bool flag){
        int n = nums.size();
        int l = 0, r = n - 1, idx = - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target){
                idx = m;
                if(flag)    r = m - 1;
                else        l = m + 1;
            } else if(nums[m] < target){
                l = m + 1;
            } else{
                r = m - 1;
            }
        }
        return idx;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums, target, true), f(nums, target, false)};
    }
};
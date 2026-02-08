class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target){
                return m;
            } 
            
            if(nums[m] > target){
                r = m - 1; ans = m;
            } else{
                l = m + 1; ans = m + 1;
            }
        }

        return ans;
    }
};
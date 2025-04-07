class Solution {
private:
    // Recursion
    bool fun(vector<int> &nums, int i, int target){
        if(i == 0){
            return nums[0] == target;
        }

        return  target == 0 || 
                fun(nums, i - 1, target) || 
                (target >= nums[i] ? fun(nums, i - 1, target - nums[i]) : false);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1){
            return false;
        }

        int n = nums.size();
        int target = sum / 2;
        // return fun(nums, n - 1, target);

        // Dp
        vector<bool> prev(target + 1, false);
        for(int val = 0; val <= target; val++){
            prev[val] = (val == nums[0]);
        }

        prev[0] = true;

        for(int i = 1; i < n; i++){
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for(int val = 1; val <= target; val++){
                curr[val] = prev[val] || (val >= nums[i] ? prev[val - nums[i]] : false);
            }
            prev = curr;
        }

        return prev[target];
    }
};
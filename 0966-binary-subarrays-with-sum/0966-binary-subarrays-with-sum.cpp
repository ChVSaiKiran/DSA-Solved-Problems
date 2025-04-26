class Solution {
private:
    int fun(vector<int>& nums, int goal, int l, int r, int sum){
        int cnt = 0;
        while(sum == goal && l <= r){
            cnt++;  sum -= nums[l++];
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ans = 0, l = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while(sum > goal && l < r){
                sum -= nums[l++];
            }

            if(sum == goal){
                ans = ans + 1 + fun(nums, goal, l + 1, r, sum - nums[l]);
            }
        }

        return ans;
    }
};
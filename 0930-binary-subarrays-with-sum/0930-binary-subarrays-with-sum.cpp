class Solution {
private:
    int f(vector<int>& nums, int goal){
        long sum = 0, l = 0, cnt = 0, n = nums.size();
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(l <= r && sum > goal) sum -= nums[l++];
            cnt += (r - l + 1);
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal - 1);
    }
};
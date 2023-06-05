class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, diff = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int lo = i + 1, hi = nums.size() - 1;
            while(lo < hi){
                long long sum = nums[i];
                sum += nums[lo];
                sum += nums[hi];
                if(abs(target - sum) < diff){
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum < target)
                    lo++;
                else
                    hi--;
            }    
        }
        return ans;
    }
};
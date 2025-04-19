class Solution {
private:
    int getLowerLimit(vector<int> &nums, int l, int h, int val, int target){
        int idx = l;
        while(l <= h){
            int m = (l + h) / 2;
            if(val + nums[m] < target){
                l = m + 1;
            }else{
                idx = m;
                h = m - 1;
            }
        }
        return idx;
    }

    int getUpperLimit(vector<int> &nums, int l, int h, int val, int target){
        int idx = h;
        while(l <= h){
            int m = (l + h) / 2;
            if(val + nums[m] > target){
                h = m - 1;
            }else{
                idx = m;
                l = m + 1;
            }
        }
        return idx;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int l = getLowerLimit(nums, i + 1, n - 1, nums[i], lower);
            int h = getUpperLimit(nums, i, n - 1, nums[i], upper);
            if(l <= h && nums[i] + nums[l] >= lower && nums[i] + nums[h] <= upper){
                ans += (h - l + 1); 
            }
        }

        return ans;
    }
};
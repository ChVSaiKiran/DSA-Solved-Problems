class Solution {
private:
    bool fun(vector<int>& nums, int maxOperations, int maxBagSize){
        long bags = 0;
        for(int i : nums){
            bags += (i/maxBagSize);
            bags += (i % maxBagSize != 0);
        }
        return bags <= nums.size() + maxOperations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int ans = -1, l = 1, r = *max_element(nums.begin(), nums.end());
        while(l <= r){
            int m = l + (r - l) / 2;
            if(fun(nums, maxOperations, m)){
                ans = m;    r = m - 1;
            } else{
                l = m + 1;
            }
        }
        return ans;
    }
};
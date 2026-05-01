class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long res = n * (n + 1) / 2;
        int l = 0, cnt = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        for(int r = 0; r < n; r++){
            cnt += (nums[r] == maxVal);
            while(cnt >= k){
                cnt -= (nums[l++] == maxVal);
            }
            res -= (r - l + 1);
        } 
        return res;
    }
};
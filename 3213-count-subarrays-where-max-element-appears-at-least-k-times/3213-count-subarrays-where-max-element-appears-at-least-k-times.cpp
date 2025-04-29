class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int l = 0, n = nums.size(), cnt = 0;
        long long ans = n * 1ll * (n + 1) / 2; // Total Subarrays
        for(int r = 0; r < n; r++){
            cnt += (nums[r] == maxNum);
            // As long as valid, make it as invalid
            while(cnt >= k){    //Since it is count related prblm, while loop is required
                cnt -= (nums[l++] == maxNum);
            }
            ans -= (r - l + 1); //Removing Subarrays that not match condition
        }
        return ans;
    }
};
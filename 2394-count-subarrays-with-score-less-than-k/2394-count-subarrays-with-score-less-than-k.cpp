class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l = 0, cnt = 0, sum = 0, n = nums.size();
        for(long long r = 0; r < n; r++){
            sum += nums[r];
            while(sum * (r - l + 1) >= k){
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};
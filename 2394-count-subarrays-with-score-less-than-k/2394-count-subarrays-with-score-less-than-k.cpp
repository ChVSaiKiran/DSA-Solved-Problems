class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l = 0, cnt = 0, sum = 0, n = nums.size(), ans = 0;
        for(long long r = 0; r < n; r++){
            sum += nums[r]; cnt++;
            while(sum * cnt >= k){
                sum -= nums[l++];   cnt--;
            }
            ans += cnt;
        }
        return ans;
    }
};
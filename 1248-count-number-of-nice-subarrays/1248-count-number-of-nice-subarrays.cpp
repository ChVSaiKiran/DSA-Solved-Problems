class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0, sum = 0, n = nums.size();
        unordered_map<int, int> mp; mp[0] = 1;

        for(int i = 0; i < n; i++){
            sum += (nums[i] % 2);

            if(mp.count(sum - k)){
                cnt += mp[sum - k];
            }

            mp[sum]++;
        }

        return cnt;
    }
};
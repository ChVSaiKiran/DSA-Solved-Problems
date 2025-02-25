class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(x > sum){
            return -1;
        }

        if(x == sum){
            return nums.size();
        }

        int k = sum - x, psum = 0, len = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            psum += nums[i];
            int d = psum - k;
            if(mp.find(d) != mp.end()){
                len = max(len, i - mp[d]);
            }
            mp[psum] = i;
        }

        return len != 0 ? nums.size() - len : -1;
    }
};
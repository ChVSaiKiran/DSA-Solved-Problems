class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> mp{{0, -1}};

        for(int i = 0; i < n; i++){
            sum = (sum + nums[i]) % k;

            if(mp.find(sum) != mp.end() && (i - mp[sum]) > 1){
                return true;
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return false;
    }
};
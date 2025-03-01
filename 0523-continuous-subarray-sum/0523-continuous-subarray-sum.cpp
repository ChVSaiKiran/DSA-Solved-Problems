class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp{{0, -1}};
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int r = sum % k;
            if(mp.count(r)){
                int len = i - mp[r];
                if(len >= 2){
                    return true;
                }
            } else{
                mp[r] = i;
            }
        }
        return false;
    }
};
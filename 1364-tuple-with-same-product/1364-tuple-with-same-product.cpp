class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                mp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto it : mp){
            if(it.second >= 2){
                int n = it.second;
                ans += 8 * (n * (n - 1) / 2);
            }
        }

        return ans;
    }
};
# define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            ll sum = tar - nums[i];
            sum -= nums[j];
            unordered_map<ll,ll> mp;
            for(int k = j + 1; k < n; k++)
                if(mp.find(sum - nums[k]) != mp.end()){
                    vector<int> temp = {nums[i],nums[j],nums[mp[sum - nums[k]]],nums[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                else
                    mp[nums[k]] =k; 
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
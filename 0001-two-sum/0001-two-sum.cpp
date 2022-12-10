class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict;
        for(int i=0;i<nums.size();i++)
        {
            auto it=dict.find(nums[i]);
            if(it==dict.end())
                dict[target-nums[i]]=i;
            else{
                vector<int> ans(2);
                ans[0]=it->second;ans[1]=i;
                return ans;
            }
        }
        return {};
    }
};
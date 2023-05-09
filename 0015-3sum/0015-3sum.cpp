class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                int sum = 0 - nums[i];
                int lo = i + 1, hi = n - 1;
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        ans.push_back({nums[i],nums[lo],nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1])
                            lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1])
                            hi--;
                    }
                    if(nums[lo] + nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};
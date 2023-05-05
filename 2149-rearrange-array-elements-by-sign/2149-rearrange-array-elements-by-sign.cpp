class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = 1;
        for(int k:nums){
            if(k >= 0){
                ans[i] = k;
                i += 2;
            }
            else{
                ans[j] = k;
                j += 2;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int i = 0, j = 0, n = nums.size();
        bool flag = true;
        while(ans.size() < nums.size()){
            if(flag){
                while(i < n && nums[i] < 0){
                    i++;
                }
                ans.push_back(nums[i++]);
            } else{
                while(j < n && nums[j] > 0){
                    j++;
                }
                ans.push_back(nums[j++]);
            }
            flag = !flag;
        }
        return ans;
    }
};
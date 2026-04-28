class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, k = nums.size() - 1;
        for(int j = 0; j <= k; j++){
            if(nums[j] == 0){
                swap(nums[i++], nums[j]);
            }

            if(nums[j] == 2){
                swap(nums[k--], nums[j--]);
            }
        }
    }
};
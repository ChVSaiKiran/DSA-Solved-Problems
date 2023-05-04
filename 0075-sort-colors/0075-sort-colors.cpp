class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        for(int x = 0; x <= j; x++){
            if(nums[x] == 0){
                swap(nums[i],nums[x]);
                i++;
            }
            if(nums[x] == 2){
                swap(nums[x],nums[j]);
                j--;
                x--;
            }
        }
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = accumulate(nums.begin(),nums.end(),0);
        int lsum = 0;
        for(int i = 0; i < nums.size(); i++){
            lsum += nums[i];
            if(lsum == rsum)
                return i;
            rsum -= nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = 0;
        for(int i:nums)
            xr = xr ^ i;
        return xr;
    }
};
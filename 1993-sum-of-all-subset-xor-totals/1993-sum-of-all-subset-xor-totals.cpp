class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int noOfSubsets = (1 << n);

        for(int cnt = 0; cnt < noOfSubsets; cnt++){
            int xr = 0;
            for(int i = 0; (1 << i) <= cnt; i++){
                if(cnt & (1 << i)){
                    xr ^= nums[i];
                }
            }
            sum += xr;
        }

        return sum;
    }
};
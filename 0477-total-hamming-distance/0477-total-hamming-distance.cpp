class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> zeros(32, 0);
        for(int i = 0; i < 32; i++){
            long val = pow(2, i);
            for(int x : nums){
                if((x & val) == 0){
                    zeros[i]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 32; i++){
            long val = pow(2, i);
            for(int x : nums){
                if(x & val){
                    ans += zeros[i];
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long val = 1;
        vector<int> ones(32, 0), zeros(32, 0);
        for(int i = 0; i < 32; i++){
            for(int x : nums){
                if(x & val){
                    ones[i]++;
                } else{
                    zeros[i]++;
                }
            }
            val *= 2;
        }

        val = 1;
        int ans = 0;
        for(int i = 0; i < 32; i++){
            for(int x : nums){
                if(x & val){
                    ans += zeros[i];
                }
            }
            val *= 2;
        }

        return ans;
    }
};
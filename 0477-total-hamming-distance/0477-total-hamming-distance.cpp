class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long val = 1, temp = 1;
        vector<int> ones(32, 0);
        for(int i = 0; i < 32; i++){
            for(int x : nums){
                if(x & val){
                    ones[i]++;
                }
            }
            val *= 2;
        }

        int ans = 0;
        for(int i = 0; i < 32; i++){
            for(int x : nums){
                if((x & temp) == 0){
                    ans += ones[i];
                }
            }
            temp *= 2;
        }

        return ans;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), pVal = 1, sVal = 1, ans = INT_MIN;
        for(int i = 0; i < n; i++){
            pVal *= nums[i];    sVal *= nums[n - 1 - i];
            ans = max({ans, pVal, sVal});
            if(pVal == 0){
                pVal = 1;
            }

            if(sVal == 0){
                sVal = 1;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevMax(n, 0);
        
        for(int i = 1; i < n; i++){
            prevMax[i] = max(prevMax[i - 1], nums[i - 1]); 
        }

        vector<int> suffMax(n, 0);
        for(int i = n - 2; i >= 0; i--){
            suffMax[i] = max(suffMax[i + 1], nums[i + 1]);
        }

        long long ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans = max(ans, (prevMax[i] - nums[i]) * 1ll * suffMax[i]);
        }

        return ans;
    }
};
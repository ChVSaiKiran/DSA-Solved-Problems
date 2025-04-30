class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i : nums){
            int cnt  = 0;
            while(i > 0){
                cnt++, i /= 10;
            }
            ans += (cnt % 2 == 0);
        }
        return ans;
    }
};
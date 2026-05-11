class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            int x = nums[i];
            while(x > 0){
                res.push_back(x % 10);  x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
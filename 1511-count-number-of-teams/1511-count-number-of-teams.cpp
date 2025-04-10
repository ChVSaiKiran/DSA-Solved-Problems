class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int j = 0; j < n; j++){
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 0;
            for(int i = 0; i < j; i++){
                x1 += (nums[j] > nums[i]);
                x2 += (nums[j] < nums[i]);
            }
            for(int k = j + 1; k < n; k++){
                y1 += (nums[j] < nums[k]);
                y2 += (nums[j] > nums[k]);
            }
            ans += (x1 * y1);
            ans += (x2 * y2);
        }
        return ans;
    }
};
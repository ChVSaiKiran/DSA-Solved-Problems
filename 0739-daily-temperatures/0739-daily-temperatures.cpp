class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for(int i = 0; i < n; i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                int idx = s.top(); s.pop();
                ans[idx] = i - idx;
            }
            s.push(i);
        }

        return ans;
    }
};
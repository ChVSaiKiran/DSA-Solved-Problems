class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> temp(101, 0);
        for(int i : nums){
            temp[i]++;
        }

        int cnt = 0;
        for(int i : temp){
            cnt += (i > 1);
        }

        int ans = 0, idx = 0, n = nums.size();
        while(cnt > 0 && idx < n){
            for(int i = idx; i < min(n, idx + 3); i++){
                temp[nums[i]]--;
                cnt -= (temp[nums[i]] == 1);
            }
            ans++; idx += 3;
        }

        return ans;
    }
};
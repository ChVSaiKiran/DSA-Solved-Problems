class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> temp(101, 0);
        vector<bool> flag(101, false);
        for(auto it : nums){
            temp[it[0]]++;  temp[it[1]]--;
            flag[it[1]] = flag[it[0]] = true;
        }
        int sum = 0, cnt = 0;
        for(int i = 1; i < 101; i++){
            sum += temp[i];
            cnt += (sum > 0 || flag[i]);
        }
        return cnt;
    }
};
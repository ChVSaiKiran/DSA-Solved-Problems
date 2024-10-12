class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> temp(1e6 + 2, 0);
        for(auto &it : intervals){
            temp[it[0]]++;
            temp[it[1] + 1]--;
        }

        int cnt = 0, ans = 0;
        for(int &i : temp){
            cnt += i;
            ans = max(ans, cnt);
        }

        return ans;
    }
};
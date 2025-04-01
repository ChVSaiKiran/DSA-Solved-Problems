class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> mp;
        for(auto it : intervals){
            mp[it[0]]++;    mp[it[1]]--;
        }

        mp[newInterval[0]]++;
        mp[newInterval[1]]--;

        int sum = 0;
        vector<vector<int>> ans;
        for(auto it : mp){
            int prev = sum;
            sum += it.second;
            if(prev == 0)
                ans.push_back({it.first});
            if(sum == 0)
                ans.back().push_back(it.first);
        }

        return ans;
    } 
};
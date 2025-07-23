class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back({intervals[0][0]});

        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > end){
                ans.back().push_back(end);
                ans.push_back({intervals[i][0]});
            }
            end = max(end, intervals[i][1]);
        }

        ans.back().push_back(end);
        return ans;
    }
};
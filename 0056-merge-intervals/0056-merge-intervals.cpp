class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while(i < n){
            int a = intervals[i][0];
            int b = intervals[i][1];
            i++;
            while(i < n && intervals[i][0] <= b)
            {
                b=max(b,intervals[i][1]);
                i++;
            }
            ans.push_back({a,b});
        }
        return ans;
    }
};
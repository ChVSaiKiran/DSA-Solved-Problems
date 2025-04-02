class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = intervals.size();
        int pl = intervals[0][0], pr = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] == pl && intervals[i][1] >= pr){
                ans--;
                pl = intervals[i][0];
                pr = intervals[i][1];
            } else if(pl <= intervals[i][0] && intervals[i][1] <= pr){
                ans--;
            } else{
                pl = intervals[i][0];
                pr = intervals[i][1];
            }
        }
        
        return ans;
    }
};
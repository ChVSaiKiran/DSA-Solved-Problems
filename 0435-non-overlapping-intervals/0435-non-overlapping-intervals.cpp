class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int prev = intervals[0][1], n = intervals.size(), ans = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prev){
                ans++;
            } else{
                prev = max(prev, intervals[i][1]);
            }
        }

        return ans;
    }
};
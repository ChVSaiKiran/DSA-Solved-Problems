class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<float,int> slope;
            int temp = 1;
            for(int j = i + 1; j < n; j++){
                int denom = points[j][0] - points[i][0];
                if( denom != 0)
                    slope[(float)(points[j][1] - points[i][1])/denom]++;
                else
                    temp++;
            }
            for(auto it:slope)
                ans = max(ans, it.second + 1);
            ans = max(ans,temp);
        }
        return ans;
    }
};
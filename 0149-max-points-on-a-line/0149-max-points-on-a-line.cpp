class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size(), ans = 0;
        if(n==1)
            return 1;
        for(int i = 0; i < n; i++)
        {
            unordered_map<float,int> dict;
            for(int j = i + 1; j < n; j++)
            {
                int denom = points[j][0] - points[i][0];
                int nume = points[j][1] - points[i][1];
                if( denom != 0)
                {
                    float slope = (float)(nume)/denom;
                    dict[slope]++;
                    ans = max(ans,dict[slope]+1);
                }
                else
                    dict[INT_MAX]++;
            }
            ans = max(ans,dict[INT_MAX]+1);
        }
        return ans;
    }
};
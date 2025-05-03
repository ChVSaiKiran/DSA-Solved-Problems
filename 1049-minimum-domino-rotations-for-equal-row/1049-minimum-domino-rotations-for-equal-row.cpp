class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), ans = INT_MAX;
        for(int val = 1; val <= 6; val++){
            int cnt1 = 0, cnt2 = 0, flag = 1;
            for(int i = 0; i < n; i++){
                if(tops[i] != val && bottoms[i] != val){
                    flag = 0;    break;
                }
                cnt1 += (tops[i] != val);
                cnt2 += (bottoms[i] != val);
            }
            if(flag){
                ans = min(ans, min(cnt1, cnt2));
            }
        }
        if(ans == INT_MAX)  ans = -1;
        return ans;
    }
};
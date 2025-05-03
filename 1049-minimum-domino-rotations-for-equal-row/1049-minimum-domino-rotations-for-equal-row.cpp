class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> a(6, 0), b(6, 0);
        int n = tops.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++){
            a[tops[i] - 1]++;   b[bottoms[i] - 1]++;
        }

        int val1 = 1, val2 = 1;
        for(int i = 1; i < 6; i++){
            if(a[i] > a[val1 - 1])  val1 = i + 1;

            if(b[i] > b[val2 - 1])  val2 = i + 1;
        }

        int val = a[val1 - 1] > b[val2 - 1] ? val1 : val2;

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

        if(ans == INT_MAX)  ans = -1;
        return ans;
    }
};
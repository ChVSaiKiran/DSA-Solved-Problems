class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, i = 0;
        for(int j : s){
            if(j >= g[i]){
                cnt++, i++;
                if(i == g.size()){
                    break;
                }
            }
        }
        return cnt;
    }
};
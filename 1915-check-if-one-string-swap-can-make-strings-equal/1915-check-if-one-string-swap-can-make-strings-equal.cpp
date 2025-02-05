class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), prev = -1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                if(prev != -1){
                    if(s1[i] != s2[prev] || s1[prev] != s2[i]){
                        return false;
                    }
                }
                cnt++;
                prev = i;
            }
        }

        return cnt == 0 || cnt == 2;
    }
};
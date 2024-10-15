class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, i = 1, j = 1;
        for(char c : s){
            if(c == '0'){
                ans += (i - j);
                j++;
            }
            i++;
        }
        return ans;
    }
};
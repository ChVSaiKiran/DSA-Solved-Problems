class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0, j = 0, cnt = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b')    b++;
            else   c++;
            while(a >= 1 && b >= 1 && c >= 1){
                if(s[j] == 'a') a--;
                else if(s[j] == 'b') b--;
                else    c--; j++;
            }
            cnt += (i - j + 1);
        }
        long t = (long) n * (n + 1) / 2;
        return t - cnt;
    }
};
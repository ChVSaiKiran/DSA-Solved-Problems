class Solution {
public:
    int numberOfSubstrings(string s) {
        long n = s.length();
        int a = 0, b = 0, c = 0;
        int l = 0, invalidCnt = 0;
        for(int r = 0; r < n; r++){
            a += s[r] == 'a';   
            b += s[r] == 'b';   
            c += s[r] == 'c';
            while(a > 0 && b > 0 && c > 0){
                a -= s[l] == 'a';   
                b -= s[l] == 'b';   
                c -= s[l] == 'c';   l++;
            }
            invalidCnt += (r - l + 1);
        }
        int ans = (n * (n + 1) / 2) - invalidCnt;
        return ans;
    }
};
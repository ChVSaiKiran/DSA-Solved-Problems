class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.length();
        for(char ch = 'A'; ch <= 'Z'; ch++){
            int j = 0, cnt = k;
            for(int i = 0; i < n; i++){
                cnt -= (s[i] != ch);
                while(cnt < 0){
                    cnt += (s[j] != ch); 
                    j++;
                }
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};
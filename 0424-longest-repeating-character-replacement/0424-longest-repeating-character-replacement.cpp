class Solution {
private:
    int fun(string &s, int k, int ch){
        int j = 0, cnt = 0;
        for(int i = 0; i < s.length(); i++){
            while(s[i] != ch && k == 0){
                k += (s[j++] != ch);
            }
            k -= (s[i] != ch);
            cnt = max(cnt, i - j + 1);
        }
        return cnt;
    }
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            ans = max(ans, fun(s, k, ch));
        }
        return ans;
    }
};
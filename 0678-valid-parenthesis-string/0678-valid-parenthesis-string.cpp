class Solution {
private:
    bool fun(string s, int i, int cnt){
        if(i == 0){
            return cnt == 0;
        }

        if(s[i - 1] == '(' && cnt == 0){
            return false;
        } else if(s[i - 1] == ')'){
            return fun(s, i - 1, cnt + 1);
        } else if(s[i - 1] == '*'){
            bool empty = fun(s, i - 1, cnt);
            bool rBrace = fun(s, i - 1, cnt + 1);
            bool lBrace = cnt > 0 && fun(s, i - 1, cnt - 1);
            return empty || rBrace || lBrace;
        } else{
            return fun(s, i - 1, cnt - 1);
        }
    }
public:
    bool checkValidString(string s) {
        // return fun(s, s.length(), 0);
        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n, 0));

        for(int i = 0; i <= n; i++){
            for(int cnt = 0; cnt < n; cnt++){
                if(i == 0){
                    dp[i][cnt] = cnt == 0;
                } else if(s[i - 1] == '(' && cnt == 0){
                    dp[i][cnt] = false;
                } else if(s[i - 1] == ')'){
                    dp[i][cnt] = cnt + 1 < n && dp[i - 1][cnt + 1];
                } else if(s[i - 1] == '*'){
                    bool empty = dp[i - 1][cnt];
                    bool rBrace = cnt + 1 < n && dp[i - 1][cnt + 1];
                    bool lBrace = cnt > 0 && dp[i - 1][cnt - 1];
                    dp[i][cnt] = empty || lBrace || rBrace;
                } else{
                    dp[i][cnt] = dp[i - 1][cnt - 1];
                }
            }
        }

        return dp[n][0];
    }
};
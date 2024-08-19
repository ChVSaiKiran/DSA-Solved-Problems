class Solution {
private:
    int f(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 == 0 && ind2 == 0){
            return dp[0][0] = (text1[0] == text2[0]);
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(ind1 == 0 || ind2 == 0){
            if(text1[ind1] == text2[ind2]){
                return dp[ind1][ind2] = 1;
            }
            return dp[ind1][ind2] = f(text1, text2, (ind1 != 0 ? ind1 - 1 : 0), (ind2 != 0 ? ind2 - 1 : 0), dp);
        }

        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + f(text1, text2, ind1 - 1, ind2 - 1, dp);
        }

        int notPick1 = f(text1, text2, ind1, ind2 - 1, dp);
        int notPick2 = f(text1, text2, ind1 - 1, ind2, dp);

        return dp[ind1][ind2] = max(notPick1, notPick2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Memoization Approach
        // int n = text1.length(), m = text2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return f(text1, text2, n - 1, m - 1, dp);

        // Tabulation Approach
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = (text1[0] == text2[0]);

        for(int ind1 = 1; ind1 < n; ind1++){
            dp[ind1][0] = (text1[ind1] == text2[0]) ? 1 : dp[ind1 - 1][0];
        }

        for(int ind2 = 1; ind2 < m; ind2++){
            dp[0][ind2] = (text1[0] == text2[ind2]) ? 1 : dp[0][ind2 - 1];
        }

        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 1; ind2 < m; ind2++){
                if(text1[ind1] == text2[ind2]){
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                } else{
                    dp[ind1][ind2] = max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
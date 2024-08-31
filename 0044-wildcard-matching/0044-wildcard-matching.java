class Solution {
    // // 0 Based Indexing
    // private int f(String s, String p, int ind1, int ind2, int[][] dp){
    //     if(ind1 < 0 && ind2 < 0)    return 1;
    //     if(ind2 < 0 && ind1 >= 0)   return 0;
    //     if(ind1 < 0){
    //         for(int i = 0; i <= ind2; i++){
    //             if(p.charAt(i) != '*'){
    //                 return 0;
    //             }
    //         }
    //         return 1;
    //     }

    //     if(dp[ind1][ind2] != -1){
    //         return dp[ind1][ind2];
    //     }

    //     if(p.charAt(ind2) == '?' || (s.charAt(ind1) == p.charAt(ind2))){
    //         return dp[ind1][ind2] = f(s, p, ind1 - 1, ind2 - 1, dp);
    //     }

    //     if(p.charAt(ind2) == '*'){
    //         int notTake = f(s, p, ind1, ind2 - 1, dp);
    //         int Take = f(s, p, ind1 - 1, ind2, dp);
    //         return dp[ind1][ind2] = notTake | Take;
    //     }

    //     return dp[ind1][ind2] = 0;
    // }

    // 1 Based Indexing
    private int f(String s, String p, int ind1, int ind2, int[][] dp){
        if(ind1 == 0 && ind2 == 0)    return 1;
        if(ind2 == 0 && ind1 > 0)   return 0;
        if(ind1 == 0){
            for(int i = 1; i <= ind2; i++){
                if(p.charAt(i - 1) != '*'){
                    return 0;
                }
            }
            return 1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(p.charAt(ind2 - 1) == '?' || (s.charAt(ind1 - 1) == p.charAt(ind2 - 1))){
            return dp[ind1][ind2] = f(s, p, ind1 - 1, ind2 - 1, dp);
        }

        if(p.charAt(ind2 - 1) == '*'){
            int notTake = f(s, p, ind1, ind2 - 1, dp);
            int Take = f(s, p, ind1 - 1, ind2, dp);
            return dp[ind1][ind2] = notTake | Take;
        }

        return dp[ind1][ind2] = 0;
    }

    public boolean isMatch(String s, String p) {
        // // Memoization Approach 0 Based Indexing
        // int n = s.length(), m = p.length();
        // int dp[][] = new int[n][m];
        // for(int row[] : dp){
        //     Arrays.fill(row, -1);
        // }
        // return f(s, p, n - 1, m - 1, dp) == 1;

        // Memoization Approach 1 Based Indexing
        int n = s.length(), m = p.length();
        int dp[][] = new int[n + 1][m + 1];
        for(int row[] : dp){
            Arrays.fill(row, -1);
        }
        return f(s, p, n, m, dp) == 1;

        // Tabulation Approach
        // int n = s.length(), m = p.length();
        // int dp[][] = new int[n + 1][m + 1];
        // dp[0][0] = 1;
        // for(int ind2 = 1; ind2 <= m; ind2++){
        //     int i = ind2;
        //     while(i > 0 && p.charAt(i - 1) == '*'){
        //         i--;
        //     }
        //     dp[0][ind2] = i == 0 ? 1 : 0;
        // }

        // for(int ind1 = 1; ind1 <= n; ind1++){
        //     for(int ind2 = 1; ind2 <= m; ind2++){
        //         if(p.charAt(ind2 - 1) == '?'){
        //             dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
        //         } else if(p.charAt(ind2 - 1) == '*'){
        //             int flag = 0;
        //             for(int i = ind1; i >= 0; i--){
        //                 flag |= dp[i][ind2 - 1];
        //             }
        //             dp[ind1][ind2] = flag;
        //         } else{
        //             dp[ind1][ind2] = (s.charAt(ind1 - 1) == p.charAt(ind2 - 1) ? 1 : 0) & dp[ind1 - 1][ind2 - 1];
        //         }
        //     }
        // }

        // return dp[n][m] == 1;
    }
}
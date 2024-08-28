class Solution {
    private int f(String s, String t, int ind1, int ind2, int dp[][]){
        if(ind1 < 0 || ind2 < 0){
            return Math.abs(ind1 - ind2);
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s.charAt(ind1) == t.charAt(ind2)){
            return dp[ind1][ind2] = f(s, t, ind1 - 1, ind2 - 1, dp);
        }

        int del = 1 + f(s, t, ind1 - 1, ind2, dp);
        int rep = 1 + f(s, t, ind1 - 1, ind2 - 1, dp);
        int ins = 1 + f(s, t, ind1, ind2 - 1, dp);

        return dp[ind1][ind2] = Math.min(del, Math.min(rep, ins));
    }
    public int minDistance(String word1, String word2) {
        // Memoization Approach
        // int n = word1.length(), m = word2.length();
        // int dp[][] = new int[n][m];

        // for(int row[] : dp){
        //     Arrays.fill(row, -1);
        // }

        // return f(word1, word2, n - 1, m - 1, dp);

        // Tabulation Approach
        // int n = word1.length(), m = word2.length();
        // int dp[][] = new int[n + 1][m + 1];

        // for(int ind1 = 0; ind1 <= n; ind1++){
        //     dp[ind1][0] = ind1;
        // }

        // for(int ind2 = 0; ind2 <= m; ind2++){
        //     dp[0][ind2] = ind2;
        // }

        // for(int ind1 = 1; ind1 <= n; ind1++){
        //     for(int ind2 = 1; ind2 <= m; ind2++){
        //         if(word1.charAt(ind1 - 1) == word2.charAt(ind2 - 1)){
        //             dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
        //         } else{
        //             int del = 1 + dp[ind1 - 1][ind2];
        //             int rep = 1 + dp[ind1 - 1][ind2 - 1];
        //             int ins = 1 + dp[ind1][ind2 - 1];
        //             dp[ind1][ind2] = Math.min(del, Math.min(rep, ins));
        //         }
        //     }
        // }

        // return dp[n][m];

        // Space Optimization Approach
        int n = word1.length(), m = word2.length();
        int prev[] = new int[m + 1];
        for(int ind2 = 0; ind2 <= m; ind2++){
            prev[ind2] = ind2;
        }

        for(int ind1 = 1; ind1 <= n; ind1++){
            int curr[] = new int[m + 1];
            curr[0] = ind1;
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(word1.charAt(ind1 - 1) == word2.charAt(ind2 - 1)){
                    curr[ind2] = prev[ind2 - 1];
                } else{
                    int del = 1 + prev[ind2];
                    int rep = 1 + prev[ind2 - 1];
                    int ins = 1 + curr[ind2 - 1];
                    curr[ind2] = Math.min(del, Math.min(rep, ins));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
}
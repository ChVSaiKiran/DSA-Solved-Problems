class Solution {
    // Palindrome
    private int f(String s, int ind1, int ind2, int dp[][]){
        if(ind1 > ind2){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s.charAt(ind1) == s.charAt(ind2)){
            return (ind1 != ind2 ? 2 : 1) + f(s, ind1 + 1, ind2 - 1, dp);
        }

        return Math.max(f(s, ind1, ind2 - 1, dp), f(s, ind1 + 1, ind2, dp));
    }

    private int lcs(String text1, String text2){
        int n = text1.length(), m = text2.length();
        int prev[] = new int[m + 1];

        for(int ind1 = 1; ind1 <= n; ind1++){
            int curr[] = new int[m + 1];
            for(int ind2 = 1; ind2 <= m; ind2++){
                if(text1.charAt(ind1 - 1) == text2.charAt(ind2 - 1)){  
                    curr[ind2] = 1 + prev[ind2 - 1];
                }
                else{
                    curr[ind2] = Math.max(prev[ind2], curr[ind2 - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
    public int longestPalindromeSubseq(String s) {
        // Memoization Approach
        // int n = s.length(), dp[][] = new int[n][n];

        // for(int[] row : dp){
        //     Arrays.fill(row, -1);
        // }
        // return f(s, 0, n - 1, dp);

        // Tabulation
        // int n = s.length(), dp[][] = new int[n + 2][n + 2];  // n + 2 because, when ind is it at extermes i.e., 1 or n
                                                                // we need to have 0's for the 0th & n + 1th boundaries

        // for(int[] row : dp){
        //     Arrays.fill(row, 0);
        // }

        // for(int ind1 = n; ind1 >= 1; ind1--){
        //     for(int ind2 = 1; ind2 <= n; ind2++){
        //         if(ind1 > ind2){
        //             dp[ind1][ind2] = 0;
        //         } else if(s.charAt(ind1 - 1) == s.charAt(ind2 - 1)){
        //             dp[ind1][ind2] = (ind1 != ind2 ? 2 : 1) + dp[ind1 + 1][ind2 - 1];
        //         } else{
        //             dp[ind1][ind2] = Math.max(dp[ind1 + 1][ind2], dp[ind1][ind2 - 1]);
        //         }
        //     }
        // }
        
        // return dp[1][n];

        // Using LCS Code
        String t = new StringBuilder(s).reverse().toString();

        return lcs(s, t);
    }
}
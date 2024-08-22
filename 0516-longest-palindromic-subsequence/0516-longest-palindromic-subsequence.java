class Solution {
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

    public int longestPalindromeSubseq(String s) {
        // Memoization Approach
        // int n = s.length(), dp[][] = new int[n][n];

        // for(int[] row : dp){
        //     Arrays.fill(row, -1);
        // }
        // return f(s, 0, n - 1, dp);

        // Tabulation
        int n = s.length(), dp[][] = new int[n + 2][n + 2];

        for(int[] row : dp){
            Arrays.fill(row, 0);
        }

        for(int ind1 = n; ind1 >= 1; ind1--){
            for(int ind2 = 1; ind2 <= n; ind2++){
                if(ind1 > ind2){
                    dp[ind1][ind2] = 0;
                } else if(s.charAt(ind1 - 1) == s.charAt(ind2 - 1)){
                    dp[ind1][ind2] = (ind1 != ind2 ? 2 : 1) + dp[ind1 + 1][ind2 - 1];
                } else{
                    dp[ind1][ind2] = Math.max(dp[ind1 + 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        
        return dp[1][n];
    }
}
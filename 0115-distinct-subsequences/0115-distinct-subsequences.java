class Solution {
    private int f(String s, String t, int ind1, int ind2, int[][] dp){
        if(ind2 < 0){
            return 1;
        }

        if(ind1 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int take = 0;
        if(s.charAt(ind1) == t.charAt(ind2)){
            take = f(s, t, ind1 - 1, ind2 - 1, dp);
        }

        int notTake = f(s, t, ind1 - 1, ind2, dp);
        
        return dp[ind1][ind2] = take + notTake;
    }
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        int dp[][] = new int[n][m];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }

        return f(s, t, n - 1, m - 1, dp);
    }
}
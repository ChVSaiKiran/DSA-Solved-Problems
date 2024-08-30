class Solution {
    private int f(String s, String p, int ind1, int ind2, int[][] dp){
        if(ind1 < 0 || ind2 < 0){
            while(ind2 >= 0 && p.charAt(ind2) == '*'){
                ind2--;
            }
            return (ind1 < 0 && ind2 < 0) ? 1 : 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(p.charAt(ind2) == '?'){
            return dp[ind1][ind2] = f(s, p, ind1 - 1, ind2 - 1, dp);
        }

        if(p.charAt(ind2) == '*'){
            int flag = 0;
            for(int i = ind1; i >= -1; i--){
                flag |= f(s, p, i, ind2 - 1, dp);
            }
            return dp[ind1][ind2] = flag;
        }

        return dp[ind1][ind2] = (s.charAt(ind1) == p.charAt(ind2) ? 1 : 0) & f(s, p, ind1 - 1, ind2 - 1, dp);
    }

    public boolean isMatch(String s, String p) {
        int n = s.length(), m = p.length();
        int dp[][] = new int[n + 1][m + 1];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }

        return f(s, p, n - 1, m - 1, dp) == 1;
    }
}
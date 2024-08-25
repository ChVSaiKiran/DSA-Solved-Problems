class Solution {
    private String f(String a, String b){
        int n = a.length(), m = b.length();
        int dp[][] = new int[n + 1][m + 1];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a.charAt(i - 1) == b.charAt(j - 1)){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        StringBuilder text = new StringBuilder();
        while(i > 0 && j > 0){
            if(a.charAt(i - 1) == b.charAt(j - 1)){
                text.append(a.charAt(i - 1));
                i--; j--;
            } else if(dp[i][j] == dp[i][j - 1]){
                j--;
            } else{
                i--;
            }
        }

        text.reverse();
        return text.toString();
    }

    public String shortestCommonSupersequence(String str1, String str2) {
        StringBuilder ans = new StringBuilder();
        String lcs = f(str1, str2);

        int n = str1.length(), m = str2.length(), l = lcs.length();
        int i = 0, j = 0, k = 0;

        while(k < l){
            while(i < n && str1.charAt(i) != lcs.charAt(k)){
                ans.append(str1.charAt(i++));
            }
            while(j < m && str2.charAt(j) != lcs.charAt(k)){
                ans.append(str2.charAt(j++));
            }
            ans.append(lcs.charAt(k));
            i++; j++; k++;
        }

        ans.append(str1.substring(i) + str2.substring(j));
        
        return ans.toString();
    }
}
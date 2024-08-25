class Solution {
    private int lcs(String s, String t){
        int n = s.length(), m = t.length();
        int prev[] = new int[m + 1];
        for(int i = 1; i <= n; i++){
            int curr[] = new int[m + 1];
            for(int j = 1; j <= m; j++){
                if(s.charAt(i - 1) == t.charAt(j - 1)){
                    curr[j] = 1 + prev[j - 1];
                } else{
                    curr[j] = Math.max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    public int minInsertions(String s) {
        int len = lcs(s, (new StringBuilder(s)).reverse().toString());
        return s.length() - len;
    }
}
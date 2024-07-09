class Solution {
    private int helper(int i, int j, int prev[][]){
        if(i == 0 && j == 0){
            return 1;
        } else if(i < 0 || j < 0){
            return 0;
        } else if(prev[i][j] != 0){
            return prev[i][j];
        } else{
            int up = helper(i - 1, j, prev);
            int lt = helper(i, j - 1, prev);
            return prev[i][j] = up + lt;
        }
    }
    public int uniquePaths(int m, int n) {
        int prev[] = new int[n];
        for(int i = 0; i < m; i++){
            int curr[] = new int[n];
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                }
                else{
                    curr[j] = (i > 0 ? prev[j] : 0) + (j > 0 ? curr[j - 1] : 0);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
}
class Solution {
    private int f(int[][] arr, int ind, int m, int n, int[][][] dp){
        if(ind == 0){
            if(arr[0][0] <= m && arr[0][1] <= n){
                return dp[ind][m][n] = 1;
            } else{
                return dp[ind][m][n] = 0;
            }
        }

        if(dp[ind][m][n] != -1){
            return dp[ind][m][n];
        }

        int notTake = 0 + f(arr, ind - 1, m, n, dp), Take = Integer.MIN_VALUE;
        if(m >= arr[ind][0] && n >= arr[ind][1]){
            Take = 1 + f(arr, ind - 1, m - arr[ind][0], n - arr[ind][1], dp);
        }

        return dp[ind][m][n] = Math.max(notTake, Take); 
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int size = strs.length;
        int[][] arr = new int[size][2];
        int[][][] dp = new int[size][m + 1][n + 1];
        for(int j = 0; j < size; j++){
            int cnt0 = 0, cnt1 = 0;
            for(char i : strs[j].toCharArray()){
                if(i == '0'){
                    cnt0++;
                } else{
                    cnt1++;
                }
            }
            arr[j][0] = cnt0;
            arr[j][1] = cnt1;
        }

        for(int[][] x : dp){
            for(int[] y : x){
                Arrays.fill(y, -1);
            } 
        }

        return f(arr, size - 1, m, n, dp);
    }
}
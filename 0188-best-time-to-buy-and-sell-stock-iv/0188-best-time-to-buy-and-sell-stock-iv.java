class Solution {
    public int maxProfit(int m, int[] prices) {
        int n = prices.length, dp[][][] = new int[n + 1][2][m + 1];

        for(int ind = n - 1; ind >= 0; ind--){
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int k = m; k > 0; k--){
                    int profit;
                    if(canBuy == 1){
                        int buy = -prices[ind] + dp[ind + 1][0][k];
                        int notBuy = 0 + dp[ind + 1][1][k];
                        profit = Math.max(buy, notBuy);
                    } else{
                        int sell = prices[ind] + dp[ind + 1][1][k - 1];
                        int notSell = 0 + dp[ind + 1][0][k];
                        profit = Math.max(sell, notSell);
                    }
                    dp[ind][canBuy][k] = profit;
                }
            }
        }

        return dp[0][1][m];
    }
}
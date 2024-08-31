class Solution {
    public int f(int[] prices, int ind, int canBuy, int[][] dp){
        if(ind >= prices.length){
            return 0;
        }

        if(dp[ind][canBuy] != -1){
            return dp[ind][canBuy];
        }

        int profit;
        if(canBuy == 1){
            int buy = -prices[ind] + f(prices, ind + 1, 0, dp);
            int notBuy = 0 + f(prices, ind + 1, 1, dp);
            profit = Math.max(buy, notBuy);
        } else{
            int sell = prices[ind] + f(prices, ind + 2, 1, dp);
            int notSell = 0 + f(prices, ind + 1, 0, dp);
            profit = Math.max(sell, notSell);
        }

        return dp[ind][canBuy] = profit;
    }

    public int maxProfit(int[] prices) {
        int n = prices.length, dp[][] = new int[n][2];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }
        
        return f(prices, 0, 1, dp);
    }
}
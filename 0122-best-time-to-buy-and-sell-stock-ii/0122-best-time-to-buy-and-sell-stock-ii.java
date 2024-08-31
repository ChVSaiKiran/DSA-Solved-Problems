class Solution {
    private int f(int[] prices, int ind, int flag, int[][] dp) {
        if(ind == prices.length){
            return 0;
        }

        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }

        int profit;
        if(flag == 1){
            int buy = f(prices, ind + 1, 0, dp) - prices[ind];
            int notBuy = f(prices, ind + 1, 1, dp);
            profit = Math.max(buy, notBuy);
        } else{
            int sell = prices[ind] + f(prices, ind + 1, 1, dp);
            int notSell = f(prices, ind + 1, 0, dp);
            profit = Math.max(sell, notSell);
        }

        return dp[ind][flag] = profit;
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n][2];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }

        return f(prices, 0, 1, dp);
    }
}
class Solution {
    private int f(int[] prices, int ind, int canBuy, int k, int dp[][][]){
        if(ind == prices.length || k == 0){
            return 0;
        }

        if(dp[ind][canBuy][k] != -1){
            return dp[ind][canBuy][k];
        }

        int profit;
        if(canBuy == 1){
            int buy = -prices[ind] + f(prices, ind + 1, 0, k, dp);
            int notBuy = 0 + f(prices, ind + 1, 1, k, dp);
            profit = Math.max(buy, notBuy);
        } else{
            int sell = prices[ind] + f(prices, ind + 1, 1, k - 1, dp);
            int notSell = 0 + f(prices, ind + 1, 0, k, dp);
            profit = Math.max(sell, notSell);
        }

        return dp[ind][canBuy][k] = profit;
    }
    public int maxProfit(int[] prices) {
        // Memoization
        // int n = prices.length, dp[][][] = new int[n][2][3];

        // for(int mat[][] : dp){
        //     for(int row[] : mat){
        //         Arrays.fill(row, -1);
        //     }
        // }

        // return f(prices, 0, 1, 2, dp);

        // Tabulation
        // int n = prices.length, dp[][][] = new int[n + 1][2][3];

        // for(int ind = n - 1; ind >= 0; ind--){
        //     for(int canBuy = 0; canBuy <= 1; canBuy++){
        //         for(int k = 2; k > 0; k--){
        //             int profit;
        //             if(canBuy == 1){
        //                 int buy = -prices[ind] + dp[ind + 1][0][k];
        //                 int notBuy = 0 + dp[ind + 1][1][k];
        //                 profit = Math.max(buy, notBuy);
        //             } else{
        //                 int sell = prices[ind] + dp[ind + 1][1][k - 1];
        //                 int notSell = 0 + dp[ind + 1][0][k];
        //                 profit = Math.max(sell, notSell);
        //             }
        //             dp[ind][canBuy][k] = profit;
        //         }
        //     }
        // }

        // return dp[0][1][2];

        // Space Optimization
        int n = prices.length, prev[][] = new int[2][3];

        for(int ind = n - 1; ind >= 0; ind--){
            int curr[][] = new int[2][3];
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int k = 2; k > 0; k--){
                    int profit;
                    if(canBuy == 1){
                        int buy = -prices[ind] + prev[0][k];
                        int notBuy = 0 + prev[1][k];
                        profit = Math.max(buy, notBuy);
                    } else{
                        int sell = prices[ind] + prev[1][k - 1];
                        int notSell = 0 + prev[0][k];
                        profit = Math.max(sell, notSell);
                    }
                    curr[canBuy][k] = profit;
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
}
class Solution {
    private int f(int[] coins, int ind, int amount, int dp[][]){
        if(ind < 0){
            return -1;
        }

        if(dp[ind][amount] != -2){
            return dp[ind][amount];
        }

        int val = coins[ind];
        
        if(amount % val == 0){
            return dp[ind][amount] = (amount / val);
        }

        int q = (amount / val), ans = Integer.MAX_VALUE;

        for(int nCoins = q; nCoins >= 0; nCoins--){
            int res = f(coins, ind - 1, amount - nCoins * val, dp);
            if(res != -1){
                ans = Math.min(ans, nCoins + res); 
            }
        }

        return dp[ind][amount] = ans != Integer.MAX_VALUE ? ans : -1;
    }

    public int coinChange(int[] coins, int amount) {
        // Memoization Approach
        int n = coins.length;
        int dp[][] = new int[n][amount + 1];

        for(int row[] : dp){
            Arrays.fill(row, -2);
        }

        Arrays.sort(coins);
        return f(coins, n - 1, amount, dp);

        // Tabulation Approach
        // int n = coins.length;
        // int dp[][] = new int[n][amt + 1];

        // for(int val = 1; val <= amt; val++){
        //     if(val % coins[0] == 0){
        //         dp[0][val] = val / coins[0];
        //     } else{
        //         dp[0][val] = -1;
        //     }
        // }

        // for(int ind = 1; ind < n; ind++){
        //     for(int val = 1; val <= amt; val++){
        //         int notPick = dp[ind - 1][val];
        //         int pick = (val >= coins[ind]) ? 1 + dp[ind][val - coins[ind]] : -1;

        //         if(notPick != -1 && pick != -1){
        //             dp[ind][val] = Math.min(notPick, pick);
        //         } else if(notPick == -1 && pick == -1){
        //             dp[ind][val] = -1;
        //         } else{
        //             dp[ind][val] = notPick != -1 ? notPick : pick;
        //         }
        //     }
        // }

        // return dp[n - 1][amt];
    }
}
class Solution {
    private int f(int[] coins, int i, int amount, int dp[][]){
        if(i == 0){
            if(amount % coins[i] == 0){
                return amount / coins[i];
            }
            return (int)1e9;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int notPick = f(coins, i - 1, amount, dp);
        int pick = Integer.MAX_VALUE;
        if(amount >= coins[i]){
            pick = 1 + f(coins, i, amount - coins[i], dp);
        }

        return dp[i][amount] = Math.min(pick, notPick);
    }

    public int coinChange(int[] coins, int amount) {
        // Memoization Approach
        // int n = coins.length;
        // int dp[][] = new int[n][amount + 1];

        // for(int row[] : dp){
        //     Arrays.fill(row, -1);
        // }

        // int ans = f(coins, n - 1, amount, dp);
        // if(ans == 1e9){
        //     return -1;
        // }

        // return ans;

        // Tabulation Approach
        // int n = coins.length;
        // int dp[][] = new int[n][amount + 1];

        // for(int j = 0; j <= amount; j++){
        //     if(j % coins[0] == 0){
        //         dp[0][j] = j / coins[0];
        //     }else{
        //         dp[0][j] = (int)1e9;
        //     }
        // }

        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j <= amount; j++){
        //         int notPick = dp[i - 1][j];
        //         int pick = Integer.MAX_VALUE;
        //         if(j >= coins[i]){
        //             pick = 1 + dp[i][j - coins[i]];
        //         }
        //         dp[i][j] = Math.min(pick, notPick);
        //     }
        // }

        // int ans = dp[n - 1][amount];
        // if(ans == 1e9){
        //     return -1;
        // }

        // return ans;

        // Space Optimization approach
        int n = coins.length;
        int prev[] = new int[amount + 1];

        for(int j = 0; j <= amount; j++){
            if(j % coins[0] == 0){
                prev[j] = j / coins[0];
            }else{
                prev[j] = (int)1e9;
            }
        }

        for(int i = 1; i < n; i++){
            int curr[] = new int[amount + 1];
            for(int j = 0; j <= amount; j++){
                int notPick = prev[j];
                int pick = Integer.MAX_VALUE;
                if(j >= coins[i]){
                    pick = 1 + curr[j - coins[i]];
                }
                curr[j] = Math.min(pick, notPick);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans == 1e9){
            return -1;
        }

        return ans;
    }
}
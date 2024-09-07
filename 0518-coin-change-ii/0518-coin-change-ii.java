class Solution {
    private int f(int[] coins, int i, int amount, int dp[][]){
        if(i == 0){
            if(amount % coins[i] == 0)
                return 1;
            else
                return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int pick = 0, notPick = f(coins, i - 1, amount, dp);

        if(amount >= coins[i]){
            pick = f(coins, i, amount - coins[i], dp);
        }

        return dp[i][amount] = notPick + pick;
    }

    public int change(int amount, int[] coins) {
        // Memoization Approach
        // int n = coins.length, dp[][] = new int[n][amount + 1];
        // for(int row[] : dp){
        //     Arrays.fill(row, -1);
        // }
        // return f(coins, n - 1, amount, dp);

        // Tabulation Approach
        // int n = coins.length, dp[][] = new int[n][amount + 1];
        // for(int val = 0; val <= amount; val++){
        //     dp[0][val] = (val % coins[0] == 0) ? 1 : 0;
        // }

        // for(int i = 1; i < n; i++){
        //     for(int val = 0; val <= amount; val++){
        //         int pick = 0, notPick = dp[i - 1][val];
        //         if(val >= coins[i]){
        //             pick = dp[i][val - coins[i]];
        //         }
        //         dp[i][val] = pick + notPick;
        //     }
        // }

        // return dp[n - 1][amount];

        // Space Optimization Approach
        int n = coins.length, prev[] = new int[amount + 1];
        for(int val = 0; val <= amount; val++){
            prev[val] = (val % coins[0] == 0) ? 1 : 0;
        }

        for(int i = 1; i < n; i++){
            int curr[] = new int[amount + 1];
            for(int val = 0; val <= amount; val++){
                int pick = 0, notPick = prev[val];
                if(val >= coins[i]){
                    pick = curr[val - coins[i]];
                }
                curr[val] = pick + notPick;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
}
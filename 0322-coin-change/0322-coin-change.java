class Solution {
    private int f(int[] coins, int amount, int i, int dp[][]){
        if(i == 0){
            if(amount % coins[i] == 0){
                return amount / coins[i];
            }
            return (int)1e9;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int notPick = f(coins, amount, i - 1, dp);
        int pick = Integer.MAX_VALUE;
        if(amount >= coins[i]){
            pick = 1 + f(coins, amount - coins[i], i, dp);
        }

        return dp[i][amount] = Math.min(pick, notPick);
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int dp[][] = new int[n][amount + 1];

        for(int row[] : dp){
            Arrays.fill(row, -1);
        }

        int ans = f(coins, amount, n - 1, dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
}
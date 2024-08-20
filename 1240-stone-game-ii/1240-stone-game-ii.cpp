class Solution {
private:
    long long f(vector<int> &piles, int ind, int M, int isAlice, vector<vector<vector<long long>>> &dp) {
    if (ind >= piles.size()) {
        return 0;
    }

    if(dp[ind][M][isAlice] != -1){
        return dp[ind][M][isAlice];
    }

    long long currMax = isAlice ? 0 : LLONG_MAX; // Use LLONG_MAX for long long
    long long sum = 0;

    for (int x = 1; x <= 2 * M; x++) {
        if (x + ind > piles.size()) {
            break;
        }

        sum += piles[ind + x - 1];
        if (isAlice == 1) {
            currMax = max(currMax, sum + f(piles, ind + x, min(max(M, x), (int)piles.size()), 0, dp));
        } else {
            currMax = min(currMax, f(piles, ind + x, min(max(M, x), (int)piles.size()), 1, dp));
        }
    }

    return dp[ind][M][isAlice] = currMax;
}


public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n + 1, vector<long long>(2, -1)));

        return (int)f(piles, 0, 1, 1, dp);
    }
};
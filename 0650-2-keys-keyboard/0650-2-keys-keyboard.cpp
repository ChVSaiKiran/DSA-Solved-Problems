class Solution {
private:
    vector<int> getPrimes(int n) {
        vector<int> temp(n + 1, 0);
        if (n >= 0) temp[0] = 1;
        if (n >= 1) temp[1] = 1;
        
        for (int i = 2; i * i <= n; ++i) {
            if (temp[i] == 0) {
                for (int j = i * i; j <= n; j += i) {
                    temp[j] = 1;
                }
            }
        }

        return temp;
    }
public:
    int minSteps(int n) {
        if(n == 1)  return 0;

        vector<int> dp = getPrimes(n);
        if(dp[n] == 0)  return n;

        for(int num = 2; num <= n; num++){
            if(dp[num] == 0){
                dp[num] = num;
                continue;
            }
            int temp = INT_MAX;
            for(int f = 2; f * f <= num; f++){
                if(num % f == 0){
                    int q1 = f, q2 = num / f;
                    temp = min(temp, dp[q1] + 1 + (q2 - 1));
                    temp = min(temp, dp[q2] + 1 + (q1 - 1));
                }
            }
            dp[num] = temp;
        }

        return dp[n];
    }
};
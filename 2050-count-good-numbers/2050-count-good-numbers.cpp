class Solution {
private:
    long long fun(long long x, long long n, int mod){
        long long ans = 1;
        while(n){
            if(n & 1){
                ans = (ans * x) % mod;
            }
            n >>= 1;
            x = (x * x) % mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        long long cnt = n / 2;
        return (fun(4, cnt, mod) * fun(5, cnt + (n % 2), mod)) % mod;
    }
};
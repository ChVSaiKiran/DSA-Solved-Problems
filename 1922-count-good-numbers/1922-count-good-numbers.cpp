class Solution {
public:
    long long power(long long x, long long n){
        int p = 1e9 + 7;
        x = x % p;
        if(x == 0)
            return 0;
        long long ans = 1;
        while(n){
            if(n & 1)
                ans = ( ans * x ) % p;
            x = ( x * x ) % p;
            n = n >> 1;
        }
        ans = ans % p;
        return ans;
    }
    int countGoodNumbers(long long n) {
        int p = 1e9 + 7;
        if(n % 2)
            return ( power(5,n/2 + 1) * power(4, n / 2) ) % p;
        return ( power(5,n/2) * power(4, n / 2) ) % p;
    }
};
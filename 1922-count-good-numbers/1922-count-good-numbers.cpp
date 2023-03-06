long long power(long long x, long long int y)
    {
        int p = 1e9 + 7;
        long long res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0){
            if (y & 1)
                res = (res*x) % p;
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
class Solution {
public:
    int countGoodNumbers(long long n) {
        int p = 1e9 + 7;
      long long count_of_4s = n/2, count_of_5s = n - count_of_4s;
      long long ans = ((power(4LL, count_of_4s) % p*power(5LL, count_of_5s) % p) % p);
        return (int)ans;
    }
};
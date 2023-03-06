class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 1000000007
        if n % 2:
            return (pow(5,n//2+1,mod) * pow(4,n//2,mod)) % mod 
        return (pow(5,n//2,mod) * pow(4,n//2,mod)) % mod 
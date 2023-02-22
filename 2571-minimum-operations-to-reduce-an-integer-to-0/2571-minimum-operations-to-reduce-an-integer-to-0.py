class Solution:
    def minOperations(self, n: int) -> int:
        if n & n -1 == 0:
            return 1
        temp = n
        n = n | n >> 1
        n = n | n >> 2
        n = n | n >> 4
        n = n | n >> 8
        n = n | n >> 16
        n = n ^ (n >> 1)
        low = n 
        high = 2 * n
        temp = min(high - temp, temp - low)
        S = Solution()
        return 1 + S.minOperations(temp)
        
        
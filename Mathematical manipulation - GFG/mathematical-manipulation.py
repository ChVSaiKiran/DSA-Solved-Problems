#User function Template for python3

class Solution:
	def CommonFactor(self, n):
		# Code here
        fact = {}
        temp = n
        i = 2
        while i<=temp:
            while temp%i == 0:
                fact[i]=0
                temp //= i
            i+=1
        if temp!=1:
            fact[temp] = 1
        arr = fact.keys()
        ans = 0
        for i in range(2,n+1):
            for num in arr:
                if i%num == 0:
                    ans+=1
                    break
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution()
		ans = ob.CommonFactor(n)
		print(ans)

# } Driver Code Ends
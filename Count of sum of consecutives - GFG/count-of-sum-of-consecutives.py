#User function Template for python3

class Solution:
    def getCount(self, n):
        # code here 
        count = 0
        i = 1
        while i*(i+1) < n*2:
            a = (n - (i*(i+1)/2))/(i+1)
            if a -int(a) == 0:
                count+=1
            i+=1
        return count

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.getCount(N))
# } Driver Code Ends
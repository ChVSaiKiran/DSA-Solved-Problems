#User function Template for python3

#Back-end complete function Template for Python 3

class Solution:
    def find (self, N):
        # code here
        while True:
            temp = N
            prev = 10
            while temp:
                if temp%10 > prev:
                    break
                prev = temp%10
                temp//=10
            if temp==0:
                return N
            N-=1
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        ob = Solution()
        print(ob.find(N))
# } Driver Code Ends
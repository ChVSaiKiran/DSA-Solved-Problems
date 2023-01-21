#User function Template for python3
class Solution:
    def bitsAreInAltOrder (self, n):
        # code here 
        arr = bin(n)
        ele = arr[0]
        i = 1
        while i < len(arr):
            if arr[i] == ele:
                return 0
            ele = arr[i]
            i+=1
        return 1    


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.bitsAreInAltOrder(n))
# } Driver Code Ends
#User function Template for python3

def uniqueRow(row, col, matrix):
    #complete the function
    mydict = {}
    ans = []
    i = 0
    while i < len(matrix):
        row = matrix[i:i+col]
        if tuple(row) not in mydict:
            mydict[tuple(row)] = 0
            ans.append(row)
        i+=col
    return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():
    testcase = int(input())
    while(testcase):
        s = input().split()
        row = int(s[0])
        col = int(s[1])
        matrix = input().split()
        
        a = uniqueRow(row, col, matrix)
        
        for row in a:
            for value in row:
                print(value,end = " ")
            print("$",end = "")
        print()
        testcase -= 1

if __name__ == "__main__":
    main()
# } Driver Code Ends
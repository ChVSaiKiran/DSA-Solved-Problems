//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
long long temp = 1000000007;
class Solution{   
public:
    int countPaths(int n){
        // code here
        if(n < 2)
            return 0;
        int ans = 3;
        for(long i = 3; i <= n; i++)
        {
            if(i%2)
                ans = (3 * ((ans - 1)  % temp)) % temp;
            else
                ans = (3 * ((ans + 1)  % temp)) % temp;
        }
        return ans % temp;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
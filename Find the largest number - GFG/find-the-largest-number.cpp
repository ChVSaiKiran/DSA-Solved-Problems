//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    int find(int n){
        // code here
        while(true){
            int temp = n, prev = 10;
            while(temp){
                if(temp%10 > prev)
                    break;
                prev = temp%10;
                temp/=10;
            }
            if(temp==0)
                return n;
            n--;
        }
        return 0;
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
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
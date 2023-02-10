//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int b = 0, a = 0, l = 0, n = 0, o = 0;
        for(char i:s){
            if(i == 'b')
                b++;
            else if(i == 'a')
                a++;
            else if(i == 'l')
                l++;
            else if(i == 'n')
                n++;
            else if(i == 'o')
                o++;
        }
        l = l/2;
        o = o/2;
        return min(b,min(a,min(l,min(o,n))));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
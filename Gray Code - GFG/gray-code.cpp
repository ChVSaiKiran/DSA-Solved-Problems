//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        string s;
        for(int i = 1; i <= n; i++) s += "0";
        vector<string> ans(1,s);
        int size = 1, k = 0, len = n;
        while(n--){
            for(int i = size - 1; i>= 0; i--){
                string temp = ans[i];
                temp[len - k - 1] = '1';
                ans.push_back(temp);
            }
            k++;
            size *= 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}




// } Driver Code Ends
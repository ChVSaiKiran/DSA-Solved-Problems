//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
          unordered_map<char,int> hash;
          for(int i = 0; i < n; i++)    hash[x[i]] = b[i];
          
            int sum = 0, msum = INT_MIN, ind = -1, sind = 0, len = 0;
            
            for(int i = 0; i < w.length(); i++){
                
                if(hash.find(w[i]) != hash.end())
                    sum += hash[w[i]];
                else
                    sum += w[i];
                    
                if(sum > msum){
                    msum = sum;
                    sind = ind + 1;
                    len = i + 1 - sind;
                }
                if (sum < 0){
                    ind = i;
                    sum = 0;
                }
            }
            // cout<<msum<<" "<<sum<<
            string ans = w.substr(sind,len);
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
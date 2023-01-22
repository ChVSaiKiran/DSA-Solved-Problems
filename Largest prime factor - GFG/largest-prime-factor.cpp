//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        unordered_map<long long int,long long int> mapp;
        long long int i = 2;
        while(i<=N){
            while(N%i == 0){
                mapp[i]++;
                N/=i;
            }
            i++;
        }
        long long int ans = 1;
        for(auto it:mapp)
            ans = max(it.first,ans);
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
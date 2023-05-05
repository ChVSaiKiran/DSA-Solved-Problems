//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int n = *max_element(arr,arr+N) + 1;
      vector<int> temp(n);
      for(int i = 0; i < N; i++)
            temp[arr[i]]++;
        int ans = 0, count = 1;
        for(int i = 1; i < n - 1; i++){
            count  = (temp[i] > 0 && temp[i+1] > 0)? count + 1 : 1;
            ans = max(ans,count);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
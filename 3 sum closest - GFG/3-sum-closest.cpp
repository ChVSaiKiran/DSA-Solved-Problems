//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        sort(A,A+N);
        int diff = INT_MAX, ele = INT_MIN;
        for(int i = 0; i < N; i++){
            int sum = X - A[i];
            int lo = i + 1, hi = N - 1;
            while(lo < hi){
                if(abs(sum - A[lo] - A[hi]) < diff){
                    diff = abs(sum - A[lo] - A[hi]);
                    ele = A[lo] + A[hi] + A[i];
                }
                else if(abs(sum - A[lo] - A[hi]) == diff && A[lo] + A[hi] + A[i] > ele)
                    ele = A[lo] + A[hi] + A[i];
                if(A[lo] + A[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
        return ele;
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
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends
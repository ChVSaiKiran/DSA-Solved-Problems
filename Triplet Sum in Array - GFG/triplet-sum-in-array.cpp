//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            int target = x - arr[i];
            int start = i + 1, end = n - 1;
            while (start < end){
                int sum = arr[start]+arr[end];
                if (target == sum)
                    return true;
                if (sum < target)
                    start++;
                else
                    end--;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends
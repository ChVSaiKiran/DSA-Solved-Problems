//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = arr[n - 1 - i], lo = 0, hi = n - 2 - i;
            while(lo < hi){
                if(arr[lo] + arr[hi] == sum)
                    ans++;
                if(arr[lo] + arr[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
        return ans;;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends
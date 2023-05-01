//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int ans = 0, sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ (i + 1);
            ans = ans ^ (arr[i]);
            sum1 += (i + 1);
            sum2 += arr[i];
        }
        int x = 0, y = 0, temp = ans & ~ (ans-1);
        for(int i = 0; i < n; i++){
            if((i+1) & temp)
                x ^= (i + 1);
            else
                y ^= (i + 1);
            if(arr[i] & temp)
                x ^= arr[i];
            else
                y ^= arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == x)
                count++;
        int *tempp = new int(2);
        tempp[0] = x;
        tempp[1] = y;
        if(count == 0){
            tempp[0] = y;
            tempp[1] = x;
        }
        return tempp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
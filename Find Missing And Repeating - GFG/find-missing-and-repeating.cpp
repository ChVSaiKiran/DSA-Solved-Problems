//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> A, int n) {
        // code here
        int xr = 0;
        for(int i:A)
            xr ^= i;
        for(int i = 1; i <= n; i++)
            xr ^= i;
        int lset = xr & ~(xr - 1), x = 0, y = 0;
        for(int i = 1; i <= n; i++){
            if(i & lset)
                x ^= i;
            else
                y ^= i;
        }
        for(int i:A){
            if(i & lset)
                x ^= i;
            else
                y ^= i;
        }
        for(int i:A)
            if(i == x)
                return {x,y};
        return {y,x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
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
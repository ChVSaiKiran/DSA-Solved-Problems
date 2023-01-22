//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int n) {
        // code here
        int count = 0;
        for(int i = 1; i*(i+1) < 2*n; i++){
            double a = (1.0 * n - (i*(i+1)/2))/(i+1);
            if(a -(int)a == 0)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
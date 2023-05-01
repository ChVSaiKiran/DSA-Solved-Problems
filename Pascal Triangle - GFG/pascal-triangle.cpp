//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> t1 = {1}, t2 = {1,1};
        if(n == 1) return t1;
        if(n == 2) return t2;
        ll mod = 1e9 + 7;
        for(int i = 3; i <=n; i++){
            vector<ll> temp;
            t1 = t2;
            temp.push_back(1);
            for(ll j = 1; j < i - 1; j++)
                temp.push_back((t2[j] + t2[j-1]) % mod);
            temp.push_back(1);
            t2 = temp;
        }
        return t2;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
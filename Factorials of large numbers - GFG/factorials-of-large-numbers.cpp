//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int> arr(2,1);
        int carry = 0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<arr.size();j++){
                arr[j] = arr[j] * i + carry;
                carry = arr[j]/10;
                arr[j] = arr[j]%10;
            }
            while(carry){
                arr.push_back(carry%10);
                carry/=10;
            }
            
        }
        vector<int> ans;
        for(int i=arr.size()-1;i>0;i--)
            ans.push_back(arr[i]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
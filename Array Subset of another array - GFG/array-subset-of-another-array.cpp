//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> dict1,dict2;
    for(int i=0;i<n;i++)
        dict1[arr1[i]]++;
    for(int i=0;i<m;i++)
        dict2[arr2[i]]++;
    for(auto it:dict2)
    {
        auto ptr=dict1.find(it.first);
        if(ptr==dict1.end() || ptr->second < it.second)
            return "No";
    }
    return "Yes";
}
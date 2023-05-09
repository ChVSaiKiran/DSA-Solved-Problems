//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    unordered_map<int,int> days;
    int buy = price[0],ind = 0;
    for(int i = 1; i < n; i++){
        if(price[i] >= buy){
            days[ind] = i;
        }
        ind = i;
        buy = price[i];
    }
    if(days.size() == 0){
        cout<<"No Profit";
    }
    else{
        int i;
        for(i = 0; i < n; i++){
            if(days.find(i) != days.end()){
                cout<<"("<<i<<" ";
                while(days.find(days[i]) != days.end())
                    i++;
                cout<<days[i]<<") ";
            }
            if(days[i] == n - 1)
                break;
        }
    }
    cout<<"\n";
}
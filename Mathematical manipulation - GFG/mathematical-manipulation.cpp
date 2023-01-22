//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int CommonFactor(int n){
	    // Code here
	    unordered_map<int,int> factors;
	    int temp = n;
	    int i = 2;
	    while(i<=temp){
	        while(temp%i==0){
	            temp/=i;
	            factors[i]++;
	        }
	        i++;
	    }
	    if(temp!=1)
	        factors[temp] = 0;
	    vector<int> arr;
	    for(auto it:factors)
	        arr.push_back(it.first);
	    int ans = 0;
	    for(int i = 2; i<=n;i++){
	        for(int j:arr)
	            if(i%j==0){
	                ans++;
	                break;
	            }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.CommonFactor(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
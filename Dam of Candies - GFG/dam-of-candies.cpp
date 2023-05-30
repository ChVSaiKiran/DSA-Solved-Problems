//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    {
        // Your code goes here
        int i = 0, j = n - 1, ans = 0;
        while(i <= j){
            if(height[i] <= height[j])
                ans = max(ans, (j - i - 1) * height[i++]);
            else
                ans = max(ans, (j - i - 1) * height[j--]);
        }
        return ans;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
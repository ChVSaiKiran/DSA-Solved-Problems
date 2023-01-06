//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int max2(int n){
        int count = 0;
        while(n){
            count++;
            n>>=1;
        }
        return count-1;
    }
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        // Your logic here
        if(n<3)
            return n;
        int pow2 = max2(n);
        int ans = pow2 * (1<<(pow2 - 1));
        int diff = n - (1<<pow2);
        ans += diff + countSetBits(diff) + 1;
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
struct TireNode{
    bool isend;
    vector<TireNode*> child;

    TireNode() {
        isend = false;
        child = vector<TireNode*>(26, nullptr);
    }
};
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        TireNode *root = new TireNode();
        TireNode *curr = root;
        for(int i = 0; i < k; i++){
            if(!curr -> child[str[i] - 'a'])
                curr -> child[str[i] - 'a'] = new TireNode();
            curr = curr -> child[str[i] - 'a'];
        }
        curr -> isend = true;
        int ans = 0;
        for(int wo = 0; wo < n; wo++){
            TireNode *curr = root;
            for(int i = 0; i < k; i++){
                if(!curr -> child[arr[wo][i] - 'a'])
                    break;
                curr = curr -> child[arr[wo][i] - 'a'];
            }
            if (curr && curr -> isend)
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
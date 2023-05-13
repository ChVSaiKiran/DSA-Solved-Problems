//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        int cnt = 0, ele = -1, ind = -1;
        for(int i = 0; i < n / 2; i++){
            if(arr[i] != arr[n - 1 - i]){
                if(ele == -1){
                    ele = arr[i];
                    ind = i;
                }
                else{
                    if(ele != arr[i]){
                        arr[i] = arr[i] ^ arr[ind];
                        arr[ind] = arr[i];
                    }
                    else{
                        arr[n - 1 - i] = arr[n - 1 - i] ^ arr[ind];
                        arr[n - 1 - i] = arr[i];
                    }
                    ele = -1;
                    ind = -1;
                    cnt++;
                }
            }
        }
        return ele == -1 ? cnt : cnt + 1;;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.bitMagic(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
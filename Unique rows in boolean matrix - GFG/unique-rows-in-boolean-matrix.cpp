//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends


/*You are required to complete this function*/
struct TireNode{
    bool isend;
    struct TireNode* child[2];
    TireNode(){
        isend = false;
        child[0] = child[1] = nullptr;
    }
};
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    vector<vector<int>> ans;
    TireNode *root = new TireNode();
    for(int i = 0; i < row; i++){
        TireNode *curr = root;
        for(int j = 0; j < col; j++){
            if(!curr -> child[M[i][j]])
                curr -> child[M[i][j]] = new TireNode();
            curr = curr -> child[M[i][j]];
        }
        if(!curr -> isend){
            vector<int> temp(col);
            copy(M[i],M[i] + col, temp.begin());
            ans.push_back(temp);
            curr -> isend = true;
        }
    }
    return ans;
}
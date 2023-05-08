//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int cnt1 = 0, cnt2 = 0, ele1 = -1, ele2 = -1;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0  && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1)    cnt1++;
            else if(nums[i] == ele2)    cnt2++;
            else
                cnt1--,cnt2--;
        }
        cnt1 = 0, cnt2 = 0;
        for(int i:nums){
            cnt1 += i == ele1 ? 1:0;
            cnt2 += i == ele2 ? 1:0;
        }
        vector<int> ans;
        if(cnt1 > n / 3)
            ans.push_back(ele1);
        if(cnt2 > n / 3)
            ans.push_back(ele2);
        if(ans.size() == 0)
            ans = {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
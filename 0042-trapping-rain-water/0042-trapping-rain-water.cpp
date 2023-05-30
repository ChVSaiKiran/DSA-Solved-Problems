class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> v1(n,arr[0]), v2(n, arr[n - 1]);
        for(int i = 1; i < n; i++)
            v1[i] = max(v1[i - 1], arr[i]);
        
        for(int i = n - 2; i >= 0; i--)
            v2[i] = max(v2[i + 1],arr[i]);

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(abs(v1[i] - arr[i]), abs(v2[i] - arr[i]));
        return ans;
    }
};
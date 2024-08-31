class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(k == n){
            return arr;
        }
        
        vector<int> ans;
        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = j - 1;

        while(ans.size() < k){
            int a = (i >= 0) ? (a = x - arr[i]) : INT_MAX;
            int b = (j < n) ? (b = arr[j] - x) : INT_MAX;
            ans.push_back(a <= b ? arr[i--] : arr[j++]);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
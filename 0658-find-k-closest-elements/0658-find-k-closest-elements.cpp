class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = j - 1;
        int cnt = 0, start_idx = j, end_idx = i;
        while(cnt < k){
            int a = (i >= 0) ? (a = x - arr[i]) : INT_MAX;
            int b = (j < n) ? (b = arr[j] - x) : INT_MAX;
            if(a <= b){
                start_idx = i--;
            } else{
                end_idx = j++;
            }
            cnt++;
        }

        return vector<int> (arr.begin() + start_idx, arr.begin() + end_idx + 1);
    }
};
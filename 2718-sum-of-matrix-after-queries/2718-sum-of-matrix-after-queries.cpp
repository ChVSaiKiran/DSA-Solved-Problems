class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& arr) {
        long long ans = 0, rowsize = n, colsize = n;
        vector<bool> row(n,true), col(n,true);
        for(int i = arr.size() - 1; i >= 0 && rowsize && colsize; i--){
            if(arr[i][0] && col[arr[i][1]]){
                ans += (rowsize * arr[i][2]);
                colsize--;
                col[arr[i][1]] = false;
            }
            if(!arr[i][0] && row[arr[i][1]]){
                ans += (colsize * arr[i][2]);
                rowsize--;
                row[arr[i][1]] = false;
            }
        }
        return ans;
    }
};
class Solution {
private:
    bool f(vector<vector<int>>& matrix, int k, int val){
        int n = matrix.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            int j = n - 1;
            while(j >= 0 && matrix[i][j] > val){
                j--;
            }
            cnt += (j + 1);
            if(cnt >= k)    return true;
        }
        return false;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), ans = -1;
        long low = matrix[0][0], high = matrix[n - 1][n - 1];
        while(low <= high){
            long mid = low + (high - low) / 2;
            if(f(matrix, k, mid)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }   
        }
        return ans;
    }
};
class Solution {
private:
    bool fun(int m, int n, int k, int val){
        int cnt = 0, prev = n;
        for(int i = 1; i <= m; i++){
            int j = prev;
            while((i * j) > val){
                j--;
            }
            cnt += j;
            prev = j;
            if(cnt >= k){
                return true;
            }
        }
        return false;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(fun(m, n, k, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
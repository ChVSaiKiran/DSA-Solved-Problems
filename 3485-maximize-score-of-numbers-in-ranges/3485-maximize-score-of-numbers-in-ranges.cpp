class Solution {
private:
    bool f(vector<int>& arr, int d, int x){
        int prev = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - prev >= x ){
                prev = arr[i];
            } else if(arr[i] + d - prev >= x){
                prev += x;
            } else{
                return false;
            }
        }
        return true;
    }
public:
    int maxPossibleScore(vector<int>& arr, int d) {
        sort(arr.begin(), arr.end());
        int low = 0, high = INT_MAX, ans;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(f(arr, d, mid)){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int lmax = arr[0], rmax = arr[j], ans = 0;
        while(i <= j){
            if(arr[i] <= arr[j]){
                if(lmax < arr[i])
                    lmax = arr[i];
                ans += lmax - arr[i++];
            }
            else{
                if(rmax < arr[j])
                    rmax = arr[j];
                ans += rmax - arr[j--];
            }
        }
        return ans;
    }
};
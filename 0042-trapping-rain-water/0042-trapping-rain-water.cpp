class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0, res = 0;
        while(l <= r){
            if(height[l] <= height[r]){
                res += max(0, lmax - height[l]);    
                lmax = max(lmax, height[l++]);
            } else{
                res += max(0, rmax - height[r]);
                rmax = max(rmax, height[r--]);
            }
        }
        return res;
    }
};
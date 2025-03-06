class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), xr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                xr ^= ((i * n) + j + 1);
                xr ^= grid[i][j];
            }
        }

        int pow2 = 1;
        while(xr > 0 && (xr & 1) == 0){
            pow2 *= 2;
            xr >>= 1;
        }

        int x = 0, y = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int val = (i * n) + j + 1;
                if(val & pow2){
                    x ^= val; cnt1++;
                } else{
                    y ^= val; cnt2++;
                }

                if(grid[i][j] & pow2){
                    x ^= grid[i][j];    cnt1--;
                } else{
                    y ^= grid[i][j];    cnt2--;
                }
            }
        }
        
        if(cnt1 < cnt2){
            return {x, y};
        } else{
            return {y, x};
        }                                    
    }
};
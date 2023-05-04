class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int cmin = 0, rmin = 0;
        int rmax = arr.size() - 1, cmax = arr[0].size() - 1;
        vector<int> ans;
        while((cmin <= cmax) && (rmin <= rmax)){
            for(int i = cmin; i <= cmax; i++)
                ans.push_back(arr[rmin][i]);
            rmin++;
            
            for(int i = rmin; i <= rmax; i++)
                ans.push_back(arr[i][cmax]);
            cmax--;
            if(rmin <= rmax){
                for(int i = cmax; i >= cmin; i--)
                    ans.push_back(arr[rmax][i]);
                rmax--;
            }
            if(cmin <= cmax){
                for(int i = rmax; i >= rmin; i--)
                    ans.push_back(arr[i][cmin]);
                cmin++;
            }
        }
        return ans;
    }
};
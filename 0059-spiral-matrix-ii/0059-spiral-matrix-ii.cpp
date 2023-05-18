class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int top = 0, left = 0, right = n - 1, bottom = n - 1;
        int temp = 1;
        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++)
                ans[top][i] = temp++;
            top++;
            
            for(int i = top; i <= bottom; i++)
                ans[i][right] = temp++;
            right--;
            
            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    ans[bottom][i] = temp++;
                bottom--;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    ans[i][left] = temp++;
                left++;
            }
        }
        return ans;
    }
};
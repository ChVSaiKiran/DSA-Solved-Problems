class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> temp;
        int ind = -1;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                ind++;
                if(!matrix[i][j])
                    temp.push_back(ind);
            }
        for(int i:temp){
            int row = i / m, col = i % m;
            for(int j = 0; j < m; j++)
                matrix[row][j] = 0;
            for(int j = 0; j < n; j++)
                matrix[j][col] = 0;
        }
    }
};
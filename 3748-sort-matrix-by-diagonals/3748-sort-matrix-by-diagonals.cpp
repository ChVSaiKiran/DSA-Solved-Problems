class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int k = 0; k < n; k++){
            vector<int> temp;
            for(int i = 0; i + k < n; i++)
                temp.emplace_back(grid[i + k][i]);
                
            sort(temp.begin(), temp.end(), greater<int>());
            for(int i = 0; i + k < n; i++)
                grid[i + k][i] = temp[i];
        }

        for(int k = 1; k < n; k++){
            vector<int> temp;
            for(int i = 0; i + k < n; i++)
                temp.emplace_back(grid[i][i + k]);

            sort(temp.begin(), temp.end());
            for(int i = 0; i + k < n; i++)
                grid[i][i + k] = temp[i];
        }
        
        return grid;
    }
};
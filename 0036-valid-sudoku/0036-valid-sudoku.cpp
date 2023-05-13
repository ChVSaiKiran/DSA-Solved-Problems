class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr){
        for(auto it:arr){
            unordered_map<char,int> row;
            for(char i: it) row[i]++;
            for(auto each: row)
                if(each.second > 1 && each.first != '.')
                    return false;
        }
        for(int i = 0; i < 9; i++){
            unordered_map<char,int> col;
            for(int j = 0; j < 9; j++)  col[arr[j][i]]++;
            for(auto each: col)
                if(each.second > 1 && each.first != '.')
                    return false;
        }
        
        int row = 0;
        while(row < 9){
            int col = 0;
            while(col < 9){
                unordered_map<char,int> mat;
                for(int i = row; i < row + 3; i++)
                for(int j = col; j < col + 3; j++)
                    mat[arr[i][j]]++;
                for(auto each: mat)
                if(each.second > 1 && each.first != '.')
                    return false;
                col += 3;
            }
            row += 3;
        }
        return true;
    }
};
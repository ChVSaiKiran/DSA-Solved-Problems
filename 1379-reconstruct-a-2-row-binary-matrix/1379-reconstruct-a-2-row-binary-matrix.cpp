class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if(accumulate(colsum.begin(), colsum.end(), 0) != (lower + upper)){
            return {};
        }

        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            if(colsum[i] == 0){
                continue;
            } else if(colsum[i] == 2){
                if(upper == 0 || lower == 0){
                    return {};
                } else{
                    ans[0][i] = ans[1][i] = 1;
                    upper--, lower--;
                }
            } else{
                if(upper >= lower && upper != 0){
                    ans[0][i] = 1;
                    upper--;
                } else if(lower >= upper && lower != 0){
                    ans[1][i] = 1;
                    lower--;
                } else{
                    return {};
                }
                // cout << "i: " << i << " U: " << upper << " L: " << lower << "\n";
            }
        }
        return ans;
    }
};
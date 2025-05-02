class Solution {
public:
    string pushDominoes(string dominoes) {
        char prev = 'X';
        int n = dominoes.size(), val = 0;
        vector<int> temp(n, INT_MAX);
        string ans(dominoes);

        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'L' || dominoes[i] == 'R'){
                val = 0;    prev = dominoes[i];
            } else if(prev == 'R'){
                val++;  temp[i] = val; ans[i] = 'R';
            }
        }

        prev = 'X';
        for(int i = n - 1; i >= 0; i--){
            if(dominoes[i] == 'R' || dominoes[i] == 'L'){
                val = 0;    prev = dominoes[i];
            } else{
                if(prev != 'L') continue;
                val++;
                if(temp[i] > val){
                    ans[i] = 'L';
                } else if(temp[i] < val){
                    ans[i] = 'R';
                } else{
                    ans[i] = '.';
                }
            }
        }

        return ans;
    }
};
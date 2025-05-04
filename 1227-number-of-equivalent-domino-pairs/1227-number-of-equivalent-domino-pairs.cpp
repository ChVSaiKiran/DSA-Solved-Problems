class Solution {
private:
    int fun(int b){
        int val;
        switch(b){
            case 0: val = 1; break;
            case 1: val = 2; break;
            case 2: val = 4; break;
            case 3: val = 8; break;
            case 4: val = 16; break;
            case 5: val = 32; break;
            case 6: val = 64; break;
            case 7: val = 128; break;
            case 8: val = 256; break;
            case 9: val = 512; break;
            default:    val = 1024; break;
        }
        return val;
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), ans = 0;
        vector<int> temp(1000, 0);
        for(auto &it : dominoes){
            int val = fun(it[0] - 1) + fun(it[1] - 1);
            temp[val]++;
        }
        for(int i : temp){
            ans += (i * (i - 1) / 2);
        }
        return ans;
    }
};
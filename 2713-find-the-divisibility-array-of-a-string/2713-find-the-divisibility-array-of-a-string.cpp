class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        long long prev = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int val = word[i] - '0';
            prev = prev * 10 + val;
            if(prev % m == 0){
                ans[i] = 1;
                prev = 0;
            }
            prev %= m;
        }
        return ans;
    }
};
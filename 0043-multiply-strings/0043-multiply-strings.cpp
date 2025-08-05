class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        if(m > n){
            return multiply(num2, num1);
        }

        vector<int> ans(n + m + 10);
        for(int j = m - 1; j >= 0; j--){
            int x = num2[j] - '0';
            for(int i = n - 1; i >= 0; i--){
                int y = num1[i] - '0';
                int idx = m + n - 2 - i - j;
                ans[idx] += (x * y);
                ans[idx + 1] += (ans[idx] / 10);
                ans[idx] %= 10; 
            }
        }

        while(ans.size() > 1 && ans.back() == 0)  ans.pop_back();
        string res;
        for(auto it = ans.rbegin(); it != ans.rend(); it++){
            res += to_string(*it);
        }
        return res;
    }
};
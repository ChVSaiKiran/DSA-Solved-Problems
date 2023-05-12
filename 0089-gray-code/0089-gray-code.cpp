class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0,1};
        int size = 2, x = 2;
        n--;
        while(n--){
            for(int i = size - 1; i >= 0; i--){
                ans.push_back(ans[i] | x);
            }
            size *= 2;
            x *= 2;
        }
        return ans;
    }
};
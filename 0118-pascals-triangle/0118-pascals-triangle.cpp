class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1) return {{1}};
        if(n == 2) return {{1},{1,1}};
        vector<vector<int>> ans;
        vector<int> t1 = {1}, t2 = {1,1};
        for(int i = 3; i <= n; i++){
            vector<int> temp = {1};
            for(int j = 1; j < i - 1; j++)
                temp.push_back(t2[j] + t2[j - 1]);
            temp.push_back(1);
            ans.push_back(t1);
            t1 = t2;
            t2 = temp;
        }
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};
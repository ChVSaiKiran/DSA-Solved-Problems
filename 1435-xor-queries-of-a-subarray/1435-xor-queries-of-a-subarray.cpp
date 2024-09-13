class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> xors(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            xors[i] = xors[i - 1] ^ arr[i - 1];
        }

        vector<int> ans; ans.reserve(m);

        for(auto it : queries){
            ans.push_back(xors[it[0]] ^ xors[it[1] + 1]);
        }

        return ans;
    }
};
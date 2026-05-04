class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();

        vector<int> preSum;
        preSum.reserve(n);

        for(int &i : arr){
            preSum.emplace_back(i ^ (preSum.size() > 0 ? preSum.back() : 0));
        }

        vector<int> res;
        res.reserve(m);

        for(auto &it: queries){
            int l = it[0] - 1, r = it[1];
            res.push_back(preSum[r] ^ (l >= 0 ? preSum[l] : 0));
        }

        return res;
    }
};
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> preSum; preSum.reserve(n);

        for(auto &s: words){
            int i = s.front(), j = s.back(), cnt = 0;
            if((i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u') && (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')){
                cnt++;
            }
            preSum.emplace_back(cnt + (preSum.size() > 0 ? preSum.back() : 0));
        }

        vector<int> res;    res.reserve(queries.size());
        for(auto &it : queries){
            int l = it[0] - 1, r = it[1];
            res.emplace_back(preSum[r] - (l >= 0 ? preSum[l] : 0));
        }

        return res;
    }
};
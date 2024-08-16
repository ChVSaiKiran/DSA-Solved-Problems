class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), ans = 0, small = arrays[0].front(), big = arrays[0].back();

        for(int i = 1; i < n; i++){
            ans = max({ans, abs(arrays[i].back() - small), abs(big - arrays[i].front())});
            big = max(big, arrays[i].back());
            small = min(small, arrays[i].front());
        }

        return ans;
    }
};
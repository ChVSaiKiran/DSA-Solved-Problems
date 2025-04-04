class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int prev = pairs[0][1], ans = pairs.size();
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] <= prev){
                ans--;
            } else{
                prev = max(prev, pairs[i][1]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp;
        for(auto it : logs){
            mp[it[0]]++;
            mp[it[1]]--;
        }

        int maxPop = 0, ans = 0, currPop = 0;
        for(auto it : mp){
            currPop += it.second;
            if(currPop > maxPop){
                ans = it.first;
                maxPop = currPop;
            }
        }
        return ans;
    }
};
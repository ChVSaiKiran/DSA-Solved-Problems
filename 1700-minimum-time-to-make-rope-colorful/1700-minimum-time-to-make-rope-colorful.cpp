class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, prevIndx = 0;
        for(int i = 1; i < neededTime.size(); i++){
            int curr = colors[i];
            int prev = colors[prevIndx];
            if(prev != curr){
                prevIndx = i;
            } else if(neededTime[prevIndx] >= neededTime[i]){
                res += neededTime[i];
            } else{
                res += neededTime[prevIndx];
                prevIndx = i;
            }
        }
        return res;
    }
};
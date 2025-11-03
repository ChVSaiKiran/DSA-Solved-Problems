class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        stack<int> s({0});
        for(int i = 1; i < neededTime.size(); i++){
            int prev = colors[s.top()];
            int curr = colors[i];
            if(prev != curr){
                s.push(i);
            } else if(neededTime[s.top()] >= neededTime[i]){
                res += neededTime[i];
            } else{
                res += neededTime[s.top()]; s.pop();
                s.push(i);
            }
        }
        return res;
    }
};
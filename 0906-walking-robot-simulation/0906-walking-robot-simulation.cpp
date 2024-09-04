class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> ax, ay;
        for(auto it : obstacles){
            ax[it[0]].insert(it[1]);
            ay[it[1]].insert(it[0]);
        }

        int x = 0, y = 0;
        int val = 1, ans = 0;
        bool yAxis = true;
        for(int i : commands){
            if(i == -1){
                yAxis = !yAxis;
                val *= (yAxis ? -1 : 1);
            } else if(i == -2){
                val *= (yAxis ? -1 : 1);
                yAxis = !yAxis;
            } else{
                if(yAxis){
                    for(int j = 1; j <= i; j++){
                        if(ax[x].count(y + val)){
                            break;
                        }
                        y += val;                      
                    }
                } else{
                    for(int j = 1; j <= i; j++){
                        if(ay[y].count(x + val)){
                            break;
                        }
                        x += val;
                    }
                }
                ans = max(ans, (int)(pow(x, 2) + pow(y, 2)));
            }
        }
        return ans;
    }
};
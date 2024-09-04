// // Mine Code
// class Solution {
// public:
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         unordered_map<int, unordered_set<int>> st;
//         for(auto it : obstacles){
//             st[it[0]].insert(it[1]);
//         }

//         int x = 0, y = 0;
//         int val = 1, ans = 0;
//         bool yAxis = true;
//         for(int i : commands){
//             if(i == -1){
//                 yAxis = !yAxis;
//                 val *= (yAxis ? -1 : 1);
//             } else if(i == -2){
//                 val *= (yAxis ? -1 : 1);
//                 yAxis = !yAxis;
//             } else{
//                 if(yAxis){
//                     for(int j = 1; j <= i; j++){
//                         if(st[x].count(y + val)){
//                             break;
//                         }
//                         y += val;                      
//                     }
//                 } else{
//                     for(int j = 1; j <= i; j++){
//                         if(st[x + val].count(y)){
//                             break;
//                         }
//                         x += val;
//                     }
//                 }
//                 ans = max(ans, (int)(pow(x, 2) + pow(y, 2)));
//             }
//         }
//         return ans;
//     }
// };

// In Well Structured Manner
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> st;
        for(auto it : obstacles){
            st[it[0]].insert(it[1]);
        }

        vector<vector<int>> dir({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        int x = 0, y = 0, d = 0, ans = 0;

        for(int i : commands){
            if(i == -1){
                d = (d + 1) % 4;
            } else if(i == -2){
                d = (d + 4 - 1) % 4;
            } else{
                int dx = dir[d][0], dy = dir[d][1];
                for(int k = 1; k <= i; k++){
                    if(st[x + dx].count(y + dy)){
                        break;
                    }
                    x += dx, y += dy;
                }
                ans = max(ans, (int)(pow(x, 2) + pow(y, 2)));
            }
        }
        return ans;
    }
};
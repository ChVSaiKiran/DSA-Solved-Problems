class Solution {
private:
    bool fun(vector<pair<int,int>> &temp){
        int prev = temp[0].second, cnt = 0;
        for(auto it : temp){
            if(prev >= it.second){
                continue;
            }
            cnt += (prev <= it.first);
            prev = it.second;
        }
        return cnt >= 2;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> temp1, temp2;
        for(auto it : rectangles){
            temp1.push_back({it[0], it[2]});
            temp2.push_back({it[1], it[3]});
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        return fun(temp1) || fun(temp2);
    }
};
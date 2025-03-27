class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp(1002, 0);
        for(auto &it : trips){
            temp[it[1]] += it[0];
            temp[it[2]] -= it[0];
        }

        int sum = 0;
        for(int &i : temp){
            sum += i;
            if(sum > capacity){
                break;
            }
        }

        return sum <= capacity;
    }
};
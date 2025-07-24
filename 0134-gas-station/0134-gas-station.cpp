class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum  = 0, temp = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += (gas[i] - cost[i]);
            temp += (gas[i] - cost[i]);
            if(temp < 0){
                temp = 0;
                ans = i + 1;
            }
        }

        if(sum < 0) return -1;

        for(int i = 0; i < ans; i++){
            temp += (gas[i] - cost[i]);
            if(temp < 0){
                return -1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = gas.size(), i = 0, j = 0, cur_gas = 0, start = 0;
        int tc = 0, tg = 0;
        for (i = 0; i < station; i++) {
            cur_gas += gas[i];
            cur_gas -= cost[i];
            if (cur_gas < 0) {
                cur_gas = 0;
                start = i + 1;
            }
            tc += cost[i];
            tg += gas[i];
        }
        if (tc > tg)
            return -1;
        return start;
    }
};
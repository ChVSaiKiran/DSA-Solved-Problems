class Solution {
private:
    int f(vector<int>& weights, int days, int cap){
        int curr = 0;
        for(int i : weights){
            if(curr + i == cap){
                curr = 0; days--;
            } else if(curr + i > cap){
                curr = i; days--;
            } else{
                curr += i;
            }
        }
        days -= (curr != 0);

        return days >= 0;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for(int i : weights){
            l = max(l, i);
            r += i;
        }

        int ans = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(f(weights, days, m)){
                ans = m;
                r = m - 1;
            } else{
                l = m + 1;
            }
        }

        return ans;
    }
};
class Solution {
private:
    int fun(vector<int>& piles, int h, int val){
        int cnt = 0;
        for(int i : piles){
            cnt += ceil((double)i / (double)val);
        }
        return cnt <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MAX, ans = -1;
        while(l <= r){
            long m = l + (r - l) / 2;
            if(fun(piles, h, m)){
                ans = m; r = m - 1;
            } else{
                l = m + 1;
            }
        }

        return ans;
    }
};
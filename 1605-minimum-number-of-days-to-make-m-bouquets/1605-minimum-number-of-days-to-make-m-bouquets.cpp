class Solution {
private:
    bool f(vector<int>& bloomDay, int m, int k, int mid){
        int cnt = 0;
        for(int i : bloomDay){
            if(i > mid){
                cnt = 0;
            } else{
                cnt++;
                if(cnt == k){
                    m--;    cnt = 0;
                }
            }
        }
        return m <= 0;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = INT_MAX, r = INT_MIN, ans = -1;
        for(int i : bloomDay){
            l = min(i, l);
            r = max(i, r);
        }

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(f(bloomDay, m, k, mid)){
                ans = mid;
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
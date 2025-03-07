class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int prev = -1, diff = INT_MAX;
        vector<bool> temp(1e6 + 1, true);
        vector<int> ans = {-1, -1};
        for(int i = 2; i <= right; i++){
            if(!temp[i])    continue;
            
            for(int j = i * 2; j <= right; j += i){
                temp[j] = false;
            }

            if(i >= left){
                if(prev == -1){
                    prev = i;
                    continue;
                }
                if((i - prev) < diff){
                    diff = min(diff, i - prev);
                    ans = {prev, i};
                    if(diff <= 2){
                        return ans;
                    }
                }
                prev = i;
            }
        }
        return ans;
    }
};
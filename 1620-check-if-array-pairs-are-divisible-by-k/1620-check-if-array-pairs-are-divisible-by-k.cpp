class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);
        for(int i : arr){
            int extra = i % k;
            if(extra < 0){
                extra += k;
            }
            
            int req = k - extra;
            if(req == k){
                cnt[0]++;
            } else if(cnt[req] > 0){
                cnt[req]--;
            } else{
                cnt[extra]++;
            }
        }

        if(cnt[0] % 2 == 1){
            return false;
        }
        
        for(int i = 1; i < k; i++){
            if(cnt[i] > 0){
                return false;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size(), cnt = 0;
        vector<int> mp(k + 1, 0);
        
        for(int i = 0; i < n; i++){
            int r = ((arr[i] % k) + k) % k;
            if(mp[k - r] > 0){
                cnt++; mp[k - r]--;
            } else{
                r += ((r == 0) ? k : 0);
                mp[r]++;
            }
        }

        return cnt == (n / 2);
    }
};
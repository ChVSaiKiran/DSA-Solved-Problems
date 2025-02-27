class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnt = 0;
        unordered_map<int,int> mp;
        for(int i : arr){
            int r = ((i % k) + k) % k;
            int d = k - r;
            if(mp[d] > 0){
                mp[d]--;    cnt++;
            }else{
                mp[r]++;
            }
        }
    
        cnt += (mp[0]/2);
        return cnt == arr.size() / 2;
    }
};
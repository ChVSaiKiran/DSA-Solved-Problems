class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans= 0, pSum = 0, eCnt = 0, oCnt = 0, mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++){
            pSum += arr[i];
            if(pSum % 2){
                ans = (ans + 1 + eCnt) % mod;
                oCnt++;
            } else{
                ans = (ans + oCnt) % mod;
                eCnt++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j = 0, cnt = 0, ans = INT_MAX;
        for(int i = 0; i < blocks.length(); i++){
            if(blocks[i] == 'W') cnt++;
            if(i - j >= k - 1){
                ans = min(ans, cnt);
                cnt -= (blocks[j++] == 'W');
            }
        }
        return ans;
    }
};
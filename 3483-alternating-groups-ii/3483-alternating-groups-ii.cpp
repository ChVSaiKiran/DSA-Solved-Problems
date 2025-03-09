class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> temp(n, 0);
        for(int i = 1; i < n; i++){
            temp[i] = temp[i - 1] + (colors[i] != colors[i - 1]);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            int s = temp[i], e = 0;
            if((i + k - 1) < n){
                int idx = i + k - 1;
                e = temp[idx];
            } else{
                int idx = i + k - 1 - n;
                e = temp[idx] + (idx > 0 ? temp[0] : 0);
            }
            cnt += (e - s == k - 1);
            if(i == n - k)  temp[0] = temp[n - 1] + (colors[0] != colors[n - 1]);
        }

        return cnt;
    }
};
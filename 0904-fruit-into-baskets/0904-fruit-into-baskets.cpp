class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cnt1 = 0, cnt2 = 0, n = fruits.size();
        int type1 = -1, type2 = -1, ans = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(fruits[i] == type1){
                cnt1++;
            } else if(fruits[i] == type2){
                cnt2++;
            } else if(type1 == -1){
                type1 = fruits[i]; cnt1++;
            } else if(type2 == -1){
                type2 = fruits[i]; cnt2++;
            } else{
                while(cnt1 != 0 && cnt2 != 0){
                    if(fruits[j++] == type1){
                        cnt1--;
                    } else{
                        cnt2--;
                    }
                }
                if(cnt1 == 0){
                    cnt1++; type1 = fruits[i];
                } else{
                    cnt2++; type2 = fruits[i];
                }
            }
            ans = max(ans, cnt1 + cnt2);
        }
        return ans;
    }
};
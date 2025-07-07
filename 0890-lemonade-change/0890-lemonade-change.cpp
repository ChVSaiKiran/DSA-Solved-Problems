class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;
        for(int i : bills){
            if(i == 5){ 
                a++;
            } else if(a == 0){
                return false;
            } else if(i == 10){
                b++; a--;
            } else {
                if(b > 0){
                    b--; a--;
                } else if(a >= 3){
                    a -= 3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};
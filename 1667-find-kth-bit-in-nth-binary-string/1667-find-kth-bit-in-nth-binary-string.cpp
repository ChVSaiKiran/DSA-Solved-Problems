class Solution {
private:
    char fun(int i, int k, bool flag){
        // cout << i << " " << k << " " << flag << "\n";

        if(k == 1){
            return flag ? '1' : '0';
        }

        if((k & (k - 1)) == 0){
            return flag ? '0' : '1';
        }

        if(k < i){
            return fun(i / 2, k, flag);
        } else{
            return fun(i / 2, i - (k - i), !flag);
        }
    }
public:
    char findKthBit(int n, int k) {
        if(k == 1){
            return '0';
        }
        
        if((k & (k - 1)) == 0){
            return '1';
        }
        return fun(pow(2, n - 1), k, false);
    }
};
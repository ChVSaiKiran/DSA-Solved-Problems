class Solution {
private:
    char f(int i, int k, bool flag){
        if(k == 1){
            return flag ? '1' : '0';
        }

        if((k & (k - 1)) == 0){
            return flag ? '0' : '1';
        }

        return (k < i) ? f(i / 2, k, flag) : f(i / 2, i - (k - i), !flag);
    }
public:
    char findKthBit(int n, int k) {
        if(k == 1){
            return '0';
        }
        
        if((k & (k - 1)) == 0){
            return '1';
        }
        return f(pow(2, n - 1), k, false);
    }
};
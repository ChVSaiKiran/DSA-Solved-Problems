class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        long res = 0;
        if(i == n){
            return res;
        }

        int neg = s[i] == '-' ? -1 : 1;
        if(s[i] == '-' || s[i] == '+'){
            i++;
        }

        while(i < n && s[i] >= '0' && s[i] <= '9'){
            res = (res * 10) + s[i++] - '0';
            long temp = res * neg;
            if(temp > INT_MAX)  return INT_MAX;
            if(temp < INT_MIN)  return INT_MIN;
        }

        return neg * res; 
    }
};
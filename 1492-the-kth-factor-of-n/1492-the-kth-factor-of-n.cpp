class Solution {
public:
    int kthFactor(int n, int k) {
        stack<int> s;
        int i;
        for(i = 1; i * i < n; i++)
            if(n % i == 0){
                if(--k == 0)  return i;
                s.push(n/i);
            }
        if(i * i == n)  s.push(n/i);
        while(!s.empty()){
            if(--k == 0)  return s.top();
            s.pop();
        }
        return -1;
    }
};
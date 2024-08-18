class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> list(1, 1);
        int a = 0, b = 0, c = 0;
        for(int i = 1; i < n; i++){
            int x = list[a] * 2, y = list[b] * 3, z = list[c] * 5;
            list.push_back(min({x, y, z}));
            if(list[i] == x)    a++;
            if(list[i] == y)    b++;
            if(list[i] == z)    c++;    
        }
        return list.back();
    }
};
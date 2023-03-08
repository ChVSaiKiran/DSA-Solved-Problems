class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string temp = to_string(num);
        int n = temp.length();
        int count = 0, i = 0;
        for(int i = 0;i + k <= n; i++){
            int x = stoi(temp.substr(i,k));
            if(x > 0 && num % (x) == 0)
                count++;
        }
        return count;
    }
};
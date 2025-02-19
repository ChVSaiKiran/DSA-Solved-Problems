class Solution {
private:
    void fun(int n, string temp, vector<string> &comb){
        if(temp.size() == n){
            comb.push_back(temp);
        } else{
            for(char i = 'a'; i <= 'c'; i++){
                if(temp.back() != i){
                    fun(n, temp + i, comb);
                }
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> comb;
        fun(n, "a", comb);
        fun(n, "b", comb);
        fun(n, "c", comb);
        sort(comb.begin(), comb.end());
        return k <= comb.size() ? comb[k - 1] : "";
    }
};
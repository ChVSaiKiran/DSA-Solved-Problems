class Solution {
private:
    void f(int i, int &n, vector<int> &ans){
        ans.push_back(i);

        if(i * 10 <= n){
            f(i * 10, n, ans);
        }

        if((i + 1) % 10 != 0 && (i + 1) <= n){
            f(i + 1, n, ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        f(1, n, ans);
        return ans;
    }
};
class Solution {
private:
    unordered_set<string> st;
    int ans = 1;

    void fun(string &s, int i, string temp){
        if(i == s.length()){
            ans = max(ans, (int)st.size());
            return;
        }

        if(st.count(temp + s[i]) == 0){
            st.insert(temp + s[i]);
            fun(s, i + 1, "");
            st.erase(temp + s[i]);
        }

        fun(s, i + 1, temp + s[i]);
    }
public:
    int maxUniqueSplit(string s) {
        fun(s, 0, "");
        return ans;
    }
};
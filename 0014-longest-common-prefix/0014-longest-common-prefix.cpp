class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size(), i = 0;
        while(true){
            char ch = i < strs.front().size() ? strs.front()[i] : ' ';
            for(string word : strs){
                if(i > word.size() || ch != word[i]){
                    return ans;
                }
            }
            ans += ch; i++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans, temp;
        unordered_map<char,string> mp = {{'2',"abc"},
                                         {'3',"def"},
                                         {'4',"ghi"},
                                         {'5',"jkl"},
                                         {'6',"mno"},
                                         {'7',"pqrs"},
                                         {'8',"tuv"},
                                         {'9',"wxyz"}};
        for(char i: mp[digits[0]])
            ans.push_back(string(1, i));
        for(int i = 1; i < digits.size(); i++){
            swap(ans, temp), ans.clear();
            for(char j:mp[digits[i]])
                for(string k: temp)
                    ans.push_back(k + j);
        }
        return ans;
    }
};
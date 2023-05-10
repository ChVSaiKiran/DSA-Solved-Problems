class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> dumm(strs), temp;
        for(int i = 0; i < n; i++)
            sort(dumm[i].begin(),dumm[i].end());
        
        vector<bool> flag(n,true);
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(!flag[i])    continue;
            temp.push_back(strs[i]);
            for(int j = i + 1; j < n; j++)
                if(flag[j] && dumm[i] == dumm[j]){
                        temp.push_back(strs[j]);
                        flag[j] = false;
                    }
            ans.push_back(temp);
            temp = {};
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> mark(26, -1);

        //last Occurance Of Idxs
        for(int i = 0; i < n; i++){
            mark[s[i] - 'a'] = i;
        }

        int i = 0;
        vector<int> ans;
        while(i < n){
            int bIdx = i, eIdx = mark[s[i] - 'a'];
            for(int j = i; j < eIdx; j++){
                eIdx = max(mark[s[j] - 'a'], eIdx);
            }
            ans.push_back(eIdx - bIdx + 1);   i = eIdx + 1;
        }
        
        return ans;
    }
};
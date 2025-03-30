class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> temp1(26, INT_MAX), temp2(26, -1);
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            temp1[idx] = min(temp1[idx], i);
            temp2[idx] = max(temp2[idx], i);
        }

        int start = -1, end = -1;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int sIdx = temp1[s[i] - 'a'], eIdx = temp2[s[i] - 'a'];
            if(start == -1){
                if(sIdx == eIdx){
                    ans.push_back(1);
                } else{
                    start = sIdx, end = eIdx;
                }
            } else if(i == end){
                ans.push_back(end - start + 1);
                start = -1, end = -1;
            } else if(eIdx > end){
                end = eIdx;
            }
        }

        return ans;
    }
};
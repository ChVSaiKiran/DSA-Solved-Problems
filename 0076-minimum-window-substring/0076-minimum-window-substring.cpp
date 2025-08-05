class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq1(60, 0);
        for(char c : t){
            freq1[c - 'A']++;
        }
        
        int cnt1 = 0;
        for(int i : freq1){
            cnt1 += (i > 0);
        }
    
        vector<int> freq2(60, 0);
        int j = 0, cnt2 = 0;
        int ansIdx = 0, minLen = INT_MAX;

        for(int i = 0; i < s.length(); i++){
            int x = s[i] - 'A';
            freq2[x]++;

            if(freq1[x] == freq2[x]){
                cnt2++;
            }

            while(cnt1 == cnt2){
                int len = i - j + 1;
                if(minLen > len){
                    ansIdx = j;
                    minLen = len;
                }

                int y = s[j] - 'A';
                if(freq1[y] == freq2[y]){
                    cnt2--;
                }
                freq2[y]--; j++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(ansIdx, minLen);
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();

            for(int i = 0; i < word.length(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string temp = word;
                    temp[i] = ch;
                    if(st.count(temp)){
                        if(temp == endWord){
                            return lvl + 1;
                        }
                        q.push({temp, lvl + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};
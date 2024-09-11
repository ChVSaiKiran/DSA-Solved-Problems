class Solution {
private:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> &temp){
        if(word == b){
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }

        int steps = mp[word];
        for(int i = 0; i < word.size(); i++){
            char org = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(mp.count(word) && steps - mp[word] == 1){
                    temp.push_back(word);
                    dfs(word, temp);

                    temp.pop_back();
                }
            }
            word[i] = org;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> vis(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 0});
        mp[beginWord] = 0;
        vis.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord){
                break;
            }

            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(vis.count(word)){
                        vis.erase(word);
                        mp[word] = steps + 1;
                        q.push({word, steps + 1});
                    }
                }
                word[i] = org;
            }
        }

        if(mp.count(endWord)){
            b = beginWord;
            vector<string> temp = {endWord};
            dfs(endWord, temp);
        }

        return ans;
    }
};
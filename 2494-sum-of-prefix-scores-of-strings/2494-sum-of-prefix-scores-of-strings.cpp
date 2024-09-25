struct TrieNode{
    int childCnt;
    TrieNode *child[26];
    TrieNode() : childCnt(0){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class Solution {
private:
    void insert(TrieNode *root, string &word){
        TrieNode *curr = root;
        for(char &c : word){
            if(curr -> child[c - 'a'] == nullptr){
                curr -> child[c - 'a'] = new TrieNode();
            }
            curr = curr -> child[c - 'a'];
            curr -> childCnt++;
        }
    }

    int getPrefixScore(TrieNode *root, string &word){
        int val = 0;
        TrieNode *curr = root;
        for(char c : word){
            curr = curr -> child[c - 'a'];
            val += (curr -> childCnt);
        }
        return val;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *root = new TrieNode();

        for(string &s : words){
            insert(root, s);
        }

        vector<int> ans;
        ans.reserve(words.size());

        for(string &s : words){
            ans.push_back(getPrefixScore(root, s));
        }

        return ans;
    }
};
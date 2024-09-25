struct TrieNode{
    bool wordEnd;
    int childCnt;
    TrieNode *child[26];
    TrieNode() : wordEnd(false), childCnt(0){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class Solution {
private:
    int insert(TrieNode *root, string &word, int i){
        if(i == word.size()){
            root -> wordEnd = true;
            root -> childCnt++;
            return 1;
        }

        int index = word[i] - 'a';

        if(root -> child[index] == nullptr){
            root -> child[index] = new TrieNode();
        }
        
        int added = insert(root -> child[index], word, i + 1);
        root -> childCnt += added;

        return added;
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

        for(string s : words){
            insert(root, s, 0);
        }

        vector<int> ans;
        ans.reserve(words.size());

        for(string s : words){
            ans.push_back(getPrefixScore(root, s));
        }

        return ans;
    }
};
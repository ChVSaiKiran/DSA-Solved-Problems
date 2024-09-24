struct TrieNode {
    bool wordEnd;
    TrieNode* child[10];
    TrieNode(){
        wordEnd = false;
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
private:
    void insertKey(TrieNode* root, const string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            if (curr->child[c - '0'] == nullptr) {
                curr->child[c - '0'] = new TrieNode();
            }
            curr = curr->child[c - '0'];
        }
        curr->wordEnd = true;
    }

    int f(TrieNode* root, const string& key) {
        int cnt = 0;
        TrieNode* curr = root;
        for (char c : key) {
            if (curr->child[c - '0'] == nullptr) {
                return cnt;
            }
            curr = curr->child[c - '0'];
            cnt++;
        }
        return cnt;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root = new TrieNode();
        for(int i : arr1){
            insertKey(root, to_string(i));
        }

        int ans = 0;

        for(int i : arr2){
            ans = max(ans, f(root, to_string(i)));
        }

        return ans;
    }
};
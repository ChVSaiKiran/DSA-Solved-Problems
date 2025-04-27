/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int k = 0, sum = 0, currIndx = 0;
        unordered_map<int, int> mp;
        vector<pair<int, int>> rangesToRemove;
        ListNode *curr = head;

        while(curr){
            sum += (curr -> val);
            if(sum == 0){
                rangesToRemove.push_back({0, currIndx});
            }

            if(mp.find(sum) != mp.end()){
                int prevIndx = mp[sum];
                rangesToRemove.push_back({prevIndx, currIndx});
            }

            currIndx++;
            mp[sum] = currIndx;
            
            curr = curr -> next;
        }

        sort(rangesToRemove.begin(), rangesToRemove.end());
        auto prev = make_pair(-1, -1);
        vector<bool> removed(currIndx + 1, false);
        for(auto it : rangesToRemove){
            if(prev.second >= it.first){
                continue;
            }

            for(int i = it.first; i <= it.second; i++){
                removed[i] = true; 
            }

            prev = it;
        }

        ListNode *ans = nullptr, *ansCurr = nullptr;
        curr = head;
        currIndx = 0;

        while(curr){
            if(!removed[currIndx]){
                if(ans == nullptr){
                    ans = curr; ansCurr = curr;
                } else{
                    ansCurr -> next = curr;
                    ansCurr = ansCurr -> next;
                }
            }
            currIndx++;
            curr = curr -> next; 
        }

        if(ansCurr != nullptr){
            ansCurr -> next = nullptr;
        }

        return ans;
    }
};
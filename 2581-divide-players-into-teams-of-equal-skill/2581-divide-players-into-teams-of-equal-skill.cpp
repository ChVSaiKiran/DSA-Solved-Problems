class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0ll);
        long long noOfParts = skill.size() / 2;

        if(sum % noOfParts != 0)
            return -1;

        long long k = sum / noOfParts, ans = 0;
        int checkFlag = 0;

        vector<long long> temp(k, 0);

        for(int i : skill){
            if(i >= k){
                return -1;
            }
            long long req = k - i;
            if(temp[req] > 0){
                ans += (i * req);
                temp[req]--, checkFlag--;
            } else{
                temp[i]++, checkFlag++;
            }
        }

        if(checkFlag != 0){
            return -1;
        }

        return ans;
    }
};
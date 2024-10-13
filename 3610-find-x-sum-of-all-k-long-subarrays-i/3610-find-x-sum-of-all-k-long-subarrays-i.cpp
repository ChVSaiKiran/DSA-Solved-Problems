class Solution {
private:
    int fun(unordered_map<int,int> &mp, int x){
    vector<pair<int,int>> temp;
    temp.reserve(mp.size());

    for(auto it : mp){
    	temp.push_back({it.second, it.first});
    }


    sort(temp.begin(), temp.end());

    int sum = 0;
    for(auto it = temp.rbegin(); it != temp.rend(); it++){
        sum += (it -> first * it -> second);
        x--;
        if(x == 0){
        	break;
        }
    }
    return sum;
}
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> mp;
    for(int i = 0; i < k - 1; i++)
        mp[nums[i]]++;

    vector<int> ans;
    for(int i = k - 1; i < nums.size(); i++){
        mp[nums[i]]++;
        ans.push_back(fun(mp, x));
        mp[nums[i - k + 1]]--;
    }

    return ans;
    }
};
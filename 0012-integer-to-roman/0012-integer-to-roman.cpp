class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> arr = {
            {1000,"M"}, 
            {900,"CM"},
            {500,"D"},
            {400,"CD"},
            {100,"C"},
            {90,"XC"},
            {50,"L"},
            {40,"XL"},
            {10,"X"},
            {9,"IX"},
            {5,"V"},
            {4,"IV"},
            {1,"I"}
        };
        string ans;
        for(int i = 0; i < 13; i++){
            while(num >= arr[i].first){
                ans += arr[i].second;
                num -= arr[i].first;
            }
        }
        return ans;
    }
};
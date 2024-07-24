class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [mapping](int a, int b){
            int x = 0, y = 0, cnt1 = 0, cnt2 = 0;
            do{
                x = pow(10, cnt1) * mapping[a % 10] + x;
                a /= 10;
                cnt1++;
            }while(a);

            do{
                y = pow(10, cnt2) * mapping[b % 10] + y;
                b /= 10;
                cnt2++;
            }while(b);

            return x < y;
        });
        return nums;
    }
};
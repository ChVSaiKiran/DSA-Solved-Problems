class Solution {
private:
    string lessThanTwenty[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string numberToWords(int n) {
        int q, r = 0;
        string ans;
        if(n < 20){
            ans = lessThanTwenty[n];
        } else if(n < 100){
            q = n / 10, r = n % 10, ans =  tens[q];
        } else if(n < 1e3){
            q = n / 100, r = n % 100, ans = lessThanTwenty[q] + " Hundred";
        } else if(n < 1e6){
            q = n / 1e3, r = n % (int)1e3, ans = numberToWords(q) + " Thousand";
        } else if(n < 1e9){
            q = n / 1e6, r = n % (int)1e6, ans = numberToWords(q) + " Million";
        } else{
            q = n / 1e9, r = n % (int)1e9, ans =  numberToWords(q) + " Billion";
        }
        return (r == 0) ? ans : ans + " " + numberToWords(r);
    }
};
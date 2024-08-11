class Solution {
public:
    string numberToWords(int num) {
        string temp[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num < 20){
            return temp[num];
        } else if(num < 100){
            return tens[num/10] + ((num % 10 != 0) ? " " + numberToWords(num % 10) : "");
        } else if(num < 1e3){
            return temp[num/100] + " Hundred" + ((num % 100 != 0) ? " " + numberToWords(num % 100) : "");
        } else if(num < 1e6){
            return numberToWords(num/1000) + " Thousand" + ((num % 1000 != 0) ? " " + numberToWords(num % 1000) : "");
        } else if(num < 1e9){
            return numberToWords((int)(num / 1e6)) + " Million" + ((num % ((int)1e6) != 0) ? " " + numberToWords(num % ((int)1e6)) : "");
        }
        return numberToWords((int)(num / 1e9)) + " Billion" + ((num % ((int)1e9) != 0) ? " " + numberToWords(num % ((int)1e9)) : "");
    }
};
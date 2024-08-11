class Solution {
public:
    string numberToWords(int num) {
        string temp[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num < 20){
            return temp[num];
        } else if(num < 100){
            int q = num / 10, r = num % 10;
            return tens[q] + ((r != 0) ? " " + numberToWords(r) : "");
        } else if(num < 1e3){
            int q = num / 100, r = num % 100;
            return temp[q] + " Hundred" + ((r != 0) ? " " + numberToWords(r) : "");
        } else if(num < 1e6){
            int q = num / 1e3, r = num % (int)1e3;
            return numberToWords(q) + " Thousand" + (r != 0 ? " " + numberToWords(r) : "");
        } else if(num < 1e9){
            int q = num / 1e6, r = num % (int)1e6;
            return numberToWords(q) + " Million" + (r != 0 ? " " + numberToWords(r) : "");
        } else{
            int q = num / 1e9, r = num % (int)1e9;
            return numberToWords(q) + " Billion" + (r != 0 ? " " + numberToWords(r) : "");
        }
    }
};
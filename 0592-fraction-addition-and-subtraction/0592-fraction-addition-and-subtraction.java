class Solution {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int LCM(int a, int b) {
        return Math.abs(a * b) / gcd(a, b);
    }

    public String fractionAddition(String exp) {
        int n = exp.length(), i = 0;
        int x = 0, y = 1;
        while(i < n){
            int sign = 1;
            if(exp.charAt(i) == '-' || exp.charAt(i) == '+'){
                sign = exp.charAt(i) == '+' ? 1 : -1;
                i++;
            }

            int numerator = 0;
            while(i < n && exp.charAt(i) != '/'){
                int digit = exp.charAt(i) - '0';
                numerator = numerator * 10 + digit;
                i++;
            }
            numerator *= sign;

            i++; //Skip '/'

            int denominator = 0;
            while(i < n && (exp.charAt(i) != '+' && exp.charAt(i) != '-')){
                int digit = exp.charAt(i) - '0';
                denominator = denominator * 10 + digit;
                i++;
            }

            int lcm = LCM(y, denominator);

            x = (x * (lcm / y)) + (numerator * (lcm / denominator));
            y = x == 0 ? 1 : lcm;
        }

        int commonFactor = gcd(Math.abs(x), y);
        x /= commonFactor;
        y /= commonFactor;

        return String.valueOf(x) + "/" + String.valueOf(y);
    }
}
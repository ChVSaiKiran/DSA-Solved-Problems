class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Long> stk = new Stack<>();
        for(String s : tokens){
            if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")){
                long b = stk.pop(), a = stk.pop(), ans;
                if(s.equals("+")){
                    ans = a + b;
                } else if(s.equals("-")){
                    ans = a - b;
                } else if(s.equals("*")){
                    ans = a * b;
                } else{
                    ans = a / b;
                }
                stk.push(ans);
            } else{
                stk.push(Long.valueOf(s));
            }
        }
        return stk.peek().intValue();
    }
}
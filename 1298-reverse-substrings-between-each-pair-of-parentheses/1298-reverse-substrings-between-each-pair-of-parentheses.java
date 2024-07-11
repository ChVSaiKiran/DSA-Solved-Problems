class Solution {
    public String reverseParentheses(String s) {
        Stack<Integer> stk = new Stack<Integer>();
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i <  s.length(); i++){
            char x = s.charAt(i);
            if(x == '('){
                stk.push(ans.length());
            } else if(x == ')'){
                int ind = stk.pop();
                StringBuilder temp = new StringBuilder(ans.substring(ind));
                ans.delete(ind, ans.length());
                ans.append(temp.reverse());
            } else{
                ans.append(x);
            }
        }
        return ans.toString();
    }
}
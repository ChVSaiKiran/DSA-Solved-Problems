class MinStack {
    private long minTill;
    private Stack<Long> s = new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int val) {
        if(s.isEmpty()){
            s.add(0l); minTill = val;
        } else{
            s.add(val - minTill);
            if(val < minTill){ // if condition true means, stack top is negitive
                minTill = val; // Also current val is equal to updated minTill, our old minTill got changed 
            }
        }
    }
    
    public void pop() {
        long top = s.pop();
        if(top < 0){    // stack top is negative, we need to restore the old minimum, i.e., min val before pushing
            // top repesents -> pushed value - old minimum
            // minTill -> hold the pushed value
            // top = minTill - oldMin
            // oldMin = minTill - top
            minTill = minTill - top;    //restored
        }
    }
    
    public int top() {
        long top = s.peek();
        if(top < 0){ // stack top is neg, means pushed value is in minTill
            return (int)(minTill);
        } else { // stack top is positive, means pushed value not effected our minimum
            // what we pushed ? element - minTill
            // stack top = element - minTill
            // element = top + minTill
            return (int)(top + minTill);
        }
    }
    
    public int getMin() {
        return (int) minTill;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
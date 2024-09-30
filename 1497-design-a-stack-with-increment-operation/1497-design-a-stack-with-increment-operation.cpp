class CustomStack {
private:
    vector<int> stk;
    int idx = -1;
public:
    CustomStack(int maxSize) {
        stk.resize(maxSize);
    }
    
    void push(int x) {
        if(1 + idx >= stk.size()){
            return;
        }
        idx++;
        stk[idx] = x; 
    }
    
    int pop() {
        if(idx == -1){
            return idx;
        }
        return stk[idx--];
    }
    
    void increment(int k, int val) {
        if(idx == -1){
            return;
        }

        for(int i = 0; i < min(k, idx + 1); i++){
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
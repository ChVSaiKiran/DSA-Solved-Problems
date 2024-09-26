class MyCalendar {
private:
    set<pair<int,int>> st;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto val = make_pair(start, end);
        if(st.empty()){
            st.insert(val);
            return true;
        }

        auto it = upper_bound(st.begin(), st.end(), val);

        if(it != st.end()){
            if(end > it -> first){
                return false;
            }
        }

        if(it != st.begin()){
            it--;
            if(start < it -> second){
                return false;
            }
        }

        st.insert(val);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
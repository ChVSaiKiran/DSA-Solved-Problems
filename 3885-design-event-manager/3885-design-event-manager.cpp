class EventManager {
    map<int, int> mp;
    set<pair<int, int>> st;
public:
    EventManager(vector<vector<int>>& events) {
        for(const auto &it : events){
            int id = it[0], p = it[1];
            mp[id] = p;
            st.insert({p, -id}); //sort by priority, if clash, sort by descending order
        }
    }
    
    void updatePriority(int id, int np) {
        int op = mp[id];
        mp[id] = np;

        st.erase({op, -id});
        st.insert({np, -id});
    }
    
    int pollHighest() {
        if(mp.size() == 0){
            return -1;
        }

        int id = (*(st.rbegin())).second * -1;
        st.erase({mp[id], -id});
        mp.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
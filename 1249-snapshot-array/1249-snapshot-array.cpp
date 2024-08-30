class SnapshotArray {
private:
    int cnt = 0; 
    unordered_map<int, map<int, int>> mp;
public:
    SnapshotArray(int length){
        map<int, int> temp{{0, 0}};
        for(int i = 0; i < length; i++){
            mp[i] = temp;
        }
    }
    
    void set(int index, int val) {
        mp[index][cnt] = val;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id); it--;
        return it -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
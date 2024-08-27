class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string f(vector<pair<int, string>> &arr, int target){
        int low = 0, high = arr.size() - 1;
        string ans;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid].first == target){
                return arr[mid].second;
            } else if(arr[mid].first > target){
                high = mid - 1;
            } else{
                ans = arr[mid].second;
                low = mid + 1;
            }
        }
        return ans;
    }

    string get(string key, int timestamp) {
        return f(mp[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
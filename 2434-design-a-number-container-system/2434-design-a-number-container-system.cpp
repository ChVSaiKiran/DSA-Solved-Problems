class NumberContainers {
    unordered_map<int, int> mappings;
    unordered_map<int, set<int>> containers;
public:
    void change(int index, int number) {
        if(mappings.count(index)){
            int con = mappings[index];
            containers[con].erase(index);
        }

        containers[number].insert(index);
        mappings[index] = number;
    }
    
    int find(int number) {
        return containers[number].size() > 0 ? *containers[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
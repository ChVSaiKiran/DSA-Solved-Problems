class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<int, int>>> robots;

        for(int i = 0; i < positions.size(); i++){
            robots.push_back({positions[i], {healths[i], i}});
        }

        sort(robots.begin(), robots.end());

        stack<pair<int,int>> s;
        vector<pair<int,int>> temp;
        for(auto& robo : robots){
            int pos = robo.first;
            int health = robo.second.first;
            int ind = robo.second.second;
            char dir = directions[ind];
            if(dir == 'R'){
                s.push({ind, health});
            } else{
                while(!s.empty() && health > 0){
                    auto [r_ind, r_health] = s.top();
                    s.pop();
                    if(r_health == health){
                        health = 0;
                    } else if(r_health > health){
                        health = 0;
                        s.push({r_ind, r_health - 1});
                    } else{
                        health--;
                    }
                }
                if(health > 0){
                    temp.push_back({ind, health});
                } 
            }
        }

        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(auto it : temp)
            ans.push_back(it.second);
        return ans;
    }
};
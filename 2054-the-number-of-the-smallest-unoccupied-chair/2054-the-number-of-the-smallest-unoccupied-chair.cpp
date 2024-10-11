class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int tar = times[targetFriend][0];
        sort(times.begin(), times.end());

        map<int,int> mp;
        for(auto it : times){
            int sTime = it[0], eTime = it[1];
            bool flag = true;

            for(auto &[chair_num, chair_eTime] : mp){
                if(chair_eTime <= sTime){
                    if(sTime == tar){
                        return chair_num;
                    }
                    chair_eTime = eTime;
                    flag = false;
                    break;
                }
            }

            if(flag){
                if(sTime == tar){
                    return mp.size();
                }
                mp[mp.size()] = eTime;
            }
        }

        return -1;
    }
};
class Solution {
private:
    // 0 Based Indexing
    // bool f(vector<string> &arr1, vector<string> &arr2, int i, int j, int flag, vector<vector<vector<int>>> &dp){
    //     if(i < 0 && j < 0){
    //         return true;
    //     }

    //     if(i < 0 || j < 0){
    //         return flag == 0;
    //     }

    //     if(dp[i][j][flag] != -1){
    //         return dp[i][j][flag];
    //     }

    //     if(arr1[i] == arr2[j]){
    //         if(flag == 1 || flag == 2)
    //             return dp[i][j][flag] = f(arr1, arr2, i - 1, j - 1, 3, dp);
    //         else
    //             return dp[i][j][flag] = f(arr1, arr2, i - 1, j - 1, flag, dp);
    //     }

    //     if(flag == 0){
    //         bool r1 = f(arr1, arr2, i - 1, j, 1, dp);
    //         bool r2 = f(arr1, arr2, i, j - 1, 2, dp);
    //         return dp[i][j][flag] = r1 || r2;
    //     }

    //     if(flag == 1){
    //         return dp[i][j][flag] = f(arr1, arr2, i - 1, j, 1, dp);
    //     }

    //     if(flag == 2){
    //         return dp[i][j][flag] = f(arr1, arr2, i, j - 1, 2, dp);
    //     }

    //     return dp[i][j][flag] = false;
    // }

    // 1 Based Indexing
    bool f(vector<string> &arr1, vector<string> &arr2, int i, int j, int flag, vector<vector<vector<int>>> &dp){
        cout << i << " " << j << " " << flag << "\n";
        if(i < 1 && j < 1){
            return true;
        }

        if(i < 1 || j < 1){
            return flag == 0;
        }

        if(dp[i][j][flag] != -1){
            return dp[i][j][flag];
        }

        if(flag == 1){
            if(f(arr1, arr2, i - 1, j, 1, dp))
                return true;
        }

        if(flag == 2){
            if(f(arr1, arr2, i, j - 1, 2, dp))
                return true;
        }

        if(arr1[i - 1] == arr2[j - 1]){
            if(flag == 1 || flag == 2)
                return dp[i][j][flag] = f(arr1, arr2, i - 1, j - 1, 3, dp);
            else
                return dp[i][j][flag] = f(arr1, arr2, i - 1, j - 1, flag, dp);
        }

        if(flag == 0){
            bool r1 = f(arr1, arr2, i - 1, j, 1, dp);
            bool r2 = f(arr1, arr2, i, j - 1, 2, dp);
            return dp[i][j][flag] = r1 || r2;
        }

        return dp[i][j][flag] = false;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr1, arr2;
        string temp;
        stringstream ss1(sentence1), ss2(sentence2);
        while(ss1 >> temp){
            arr1.push_back(temp);
        }

        while(ss2 >> temp){
            arr2.push_back(temp);
        }

        int n = arr1.size(), m = arr2.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int>(4, -1)));

        // 0 Based Indexing
        // return f(arr1, arr2, n - 1, m - 1, 0, dp);
        // 1 Based Indexing
        // return f(arr1, arr2, n, m, 0, dp);

        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>> (m + 1, vector<bool>(4, false)));

        for(int i = 0; i <= 3; i++){
            dp[0][0][i] = true;
        }

        for(int i = 1; i <= m; i++){
            dp[0][i][0] = true;
        }

        for(int i = 1; i <= n; i++){
            dp[i][0][0] = true;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int flag = 0; flag <= 3; flag++){
                    if(flag == 1 && dp[i - 1][j][1]){
                        dp[i][j][flag] = true;
                    } else if(flag == 2 && dp[i][j - 1][2]){
                        dp[i][j][flag] = true;
                    } else if(arr1[i - 1] == arr2[j - 1]){
                        if(flag == 1 || flag == 2)
                            dp[i][j][flag] = dp[i - 1][j - 1][3];
                        else
                            dp[i][j][flag] = dp[i - 1][j - 1][flag];
                    } else if(flag == 0){
                        bool r1 = dp[i - 1][j][1];
                        bool r2 = dp[i][j - 1][2];
                        dp[i][j][flag] = r1 || r2;
                    } else{
                        dp[i][j][flag] = false;
                    }
                }
            }
        }

        return dp[n][m][0];
    }
};
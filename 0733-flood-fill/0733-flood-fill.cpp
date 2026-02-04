class Solution {
private:
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }

        int org = image[sr][sc];    image[sr][sc] = color;
        int n = image.size(), m = image[0].size();

        for(int i = 0; i < 4; i++){
            int dx = sr + row[i];
            int dy = sc + col[i];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && image[dx][dy] == org){
                floodFill(image, dx, dy, color);
            }
        }

        return image;
    }
};
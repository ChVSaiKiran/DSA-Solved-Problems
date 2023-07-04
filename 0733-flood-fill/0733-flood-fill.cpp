class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int col){
        int n = img.size(), m = img[0].size(), curr = img[sr][sc];
        if(curr == col)
            return img;
        img[sr][sc] = col;
        
        if(sc + 1 < m && curr == img[sr][sc + 1])
            floodFill(img,sr,sc + 1,col);
        
        if(sc > 0 && curr == img[sr][sc - 1])
            floodFill(img,sr,sc - 1,col);
        
        if(sr + 1 < n && curr == img[sr + 1][sc])
            floodFill(img,sr + 1,sc,col);
        
        if(sr > 0 && curr == img[sr - 1][sc])
            floodFill(img,sr - 1,sc,col);
        
        return img;
    }
};
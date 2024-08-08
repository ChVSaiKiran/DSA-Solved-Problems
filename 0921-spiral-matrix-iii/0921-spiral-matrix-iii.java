class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int ans[][] = new int[rows * cols][2];
        ans[0][0] = rStart; ans[0][1] = cStart;

        int lt = cStart, rt = cStart + 1, up = rStart, dwn = rStart + 1, ind = 1;
        while(lt >= 0 || rt < cols || up >= 0 || dwn < rows){
            if(up >= 0){
                for(int j = lt + 1; j <= rt; j++){
                    if(j >= 0 && j < cols){
                        ans[ind][0] = up;
                        ans[ind++][1] = j;
                    }
                }
            }
            lt--;

            if(rt < cols){
                for(int i = up + 1; i <= dwn; i++){
                    if(i >= 0 && i < rows){   
                        ans[ind][0] = i;
                        ans[ind++][1] = rt;
                    }
                }
            }
            up--;

            if(dwn < rows){
                for(int j = rt - 1; j >= lt; j--){
                    if(j >= 0 && j < cols){
                        ans[ind][0] = dwn;
                        ans[ind++][1] = j;
                    }
                }
            }
            rt++;

            if(lt >= 0){
                for(int i = dwn - 1; i >= up; i--){
                    if(i >= 0 && i < rows){
                        ans[ind][0] = i;
                        ans[ind++][1] = lt;
                    }
                }
            }
            dwn++;
        }
        return ans;
    }
}
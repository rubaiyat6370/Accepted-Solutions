class Solution {
    public int surfaceArea(int[][] grid) {
        int len = grid[0].length;
        int answer = 0;
        for(int i=0;i<len; i++){
            for(int j = 0;j<len;j++){
                answer += getAreaForCell(i,j,grid,len);
            }
        }
        return answer;
    }
    
    public int getAreaForCell(int i, int j, int[][] grid, int len){
        int area = 0;
        int v = grid[i][j];
        if(v>0) {
            area += 2;
                    
            area+= sideArea(i-1,j,grid,len,v);
                    
            area+= sideArea(i+1,j,grid,len,v);
                    
            area+= sideArea(i,j-1,grid,len,v);
                    
            area+= sideArea(i,j+1,grid,len,v);
        }
        return area;
    }
    
    public int sideArea(int i, int j, int[][] grid, int len, int v){
        if(isValid(i,j,len)){
            int nv = (v - grid[i][j]);
            return nv > 0 ? nv : 0;
        } else {
            return v;
        }        
    }
    
    public boolean isValid(int x, int y, int n){
        if(x>=0 && y>=0 && x<n && y <n) return true;
        return false;
    }
}

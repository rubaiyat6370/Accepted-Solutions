import java.util.*;

public class Solution {

	public static void main(String[] args) {
		Solution s = new Solution();

//		int[][] A = {
//				{0,0,0,0,0,0,0},
//				{0,0,1,0,0,0,1},
//				{0,0,0,0,0,0,0},
//				{1,0,0,0,1,0,0},
//				{0,0,0,0,0,0,0},
//				{0,0,1,0,1,0,0},
//				{0,0,0,2,0,0,0}
//				};
		int[][] A = {
				{0,0,0, 0},
				{1,0,1, 0},
				{0,0,1, 0},
				{0,2,0, 0}
				};
		System.out.println(s.solution(A));

	}
	
	public int solution(int[][] A) {
        int counter = 0;
        int z_x = 2;
        int z_y = 1;
        
        counter = getCount(A, z_x, z_y);
        
        return counter;
    }
	
	public int getCount(int[][] A, int x, int y) {
		int left = 0;
		int right = 0;
		
		if(isvalid(x-1, y-1, A.length) && isvalid(x-2, y-2, A.length)
				&& A[x-1][y-1]==1 && A[x-2][y-2]==0) {
			left = 1 + getCount(A, x-2, y-2);
		}
		
		if(isvalid(x-1, y+1, A.length) && isvalid(x-1, y+2, A.length)
				&& A[x-1][y+1]==1 && A[x-2][y+2]==0) {
			right = 1 + getCount(A, x-2, y+2);
		}
		
		return left>right? left : right;
	}
	
	public boolean isvalid(int x, int y, int len) {
		if(x<0 || y<0 || x>=len || y>=len)
			return false;
		return true;
	}

}

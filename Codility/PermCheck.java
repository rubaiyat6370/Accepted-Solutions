import java.util.*;

class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);
        int size = A.length;
        int first = 1;
         
        for(int i=0;i<size;i++){
            //System.out.println(first + " " + A[i]);
            if(first++ != A[i]) return 0;
        }
        return 1;
    }
}

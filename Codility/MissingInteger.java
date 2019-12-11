// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);
        int size = A.length;
        if(A[size-1]<=0 || A[0]>1) return 1;
        
         int counter = 1;
         for(int i=0;i<size;i++){
            if(A[i]<=0 || (i-1>=0 && A[i-1]==A[i])) continue;
            if(A[i] != counter){
                return counter;
            }
            counter++;
         }
    
        
        return counter;
    }
}

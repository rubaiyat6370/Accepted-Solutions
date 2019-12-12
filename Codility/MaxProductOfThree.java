// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);
        int size = A.length;
        return A[size-3]*A[size-1]*A[size-2] > A[0]*A[1]*A[size-1] ? A[size-3]*A[size-1]*A[size-2] : A[0]*A[1]*A[size-1];
    }
}

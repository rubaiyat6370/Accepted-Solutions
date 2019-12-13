
public class Solution {

    // Complete the twoArrays function below.
    static String twoArrays(int k, int[] A, int[] B) {
        
        Arrays.sort(A);
        Arrays.sort(B);

        for(int i=0,j=A.length-1; i<A.length;i++,j--){
            if(j>=0 && A[i]+B[j] < k)
                return "NO";
        }
        return "YES";
    }
}

/**

1
10 4
4 4 3 2 1 4 4 3 2 4
2 3 0 1 1 3 1 0 0 2
YES
**/

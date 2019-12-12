class Solution {
    public int solution(int[] A) {
        int size = A.length;
        Arrays.sort(A);
       
        for(int i=0;i<size-2;i++){
            if((long)A[i]+(long)A[i+1]>A[i+2]) return 1;
        }
        
        return 0;
    }
}

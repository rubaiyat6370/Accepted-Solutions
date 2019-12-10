class Solution {
    public int[] solution(int N, int[] A) {
        int [] answer = new int[N];
        int size = A.length;
        int max = -1;
        int lowest = 0;
        for(int i=0;i<size;i++){
            if(A[i]<=N) {
                if(answer[A[i]-1] < lowest) {
                    answer[A[i]-1] = lowest + 1;
                }
                else answer[A[i]-1] = answer[A[i]-1] + 1;
                if(answer[A[i]-1]>max)
                    max = answer[A[i]-1];
            } else if(A[i]==N+1){
                lowest = max;
            }
        }
        
        for(int i=0;i<N;i++){
            if(answer[i]<lowest) 
                answer[i] = lowest;
        }
        
        return answer;
    }
}

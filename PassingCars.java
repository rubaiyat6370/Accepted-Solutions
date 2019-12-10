class Solution {
    public int solution(int[] A) {
        int size = A.length;
        int pair = 0, zero = 0;
        for(int i=0;i<size;i++){
            if(A[i]==0){
                zero++;
            } else {
                if(pair + zero > 1000000000) return -1;
                pair = pair+zero;
                
            }
        }
       
        return pair;
    }
}

//https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

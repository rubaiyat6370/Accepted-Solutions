public int solution(int[] A) {
        int size = A.length;
        int [] sum = new int[size];
        sum[0] = A[0];
        int minDiff = 9999999;
        for(int i=1;i<size;i++){
            sum[i] = sum[i-1] + A[i];
        }
        int diff = 0;
        for(int i=0;i<size-1;i++){
            diff = Math.abs(sum[size-1] - 2*sum[i]);
            
            if(diff < minDiff){
                minDiff = sum[i];
            } 
            if(minDiff == 0) return 0;
        }
        
        return minDiff;
    }

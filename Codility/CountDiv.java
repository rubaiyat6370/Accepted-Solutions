class Solution {
    public int solution(int A, int B, int K) {
        int start = A;
        int rem = A%K;
        if(rem!=0){
            start = K-rem+A;
            if(start>B) return 0;
        }
        int counter = (B - start)/K + 1;
        
        return counter;
    }
}

/**

Your test case: [6, 17, 2]
Returned value: 6

Your test case: [6, 17, 3]
Returned value: 4

Your test case: [0, 20, 3]
Returned value: 7

Your test case: [2, 20, 3]
Returned value: 6

Your test case: [3, 20, 3]
Returned value: 6

Your test case: [1, 7, 11]
Returned value: 0

Your test case: [0, 0, 11]
Returned value: 1

Your test case: [11, 11, 11]
Returned value: 1

Your test case: [10, 10, 7]
Returned value: 0

**/

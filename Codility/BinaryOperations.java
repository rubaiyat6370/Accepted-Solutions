/**
You are given a binary string A of any positive integer where 1<=A<=1000000. If the number is odd, you have to subtract 1 from it.
If the number is even, you have to divide it by 2. This 2 operations continues until the number is 0. Now write a program, that will 
return the number of operations it take to become zero.

input : "000111001101"
output: 14
input : "000000000"
output: 0

**/

public int solution(String A) {
        int counter = 0;
        int size = A.length();
        int start = 0;
        int numberOfOne = 0;
        int numberOfZero = 0;
        for(int i=0;i<size;i++) {
        	if(A.charAt(i)=='1') {
        		numberOfOne++;
        		start = 1;
        	} else if(A.charAt(i) == '0' && start == 1) {
        		numberOfZero++;
        	}
        }
        
        counter = numberOfOne*2 + numberOfZero - 1;
        return counter > 0 ? counter : 0;
    }

// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int[] solution(String S, int[] P, int[] Q) {
        int size_s = S.length();
        int size_p = P.length;
        
        Map<Character,Integer> genom = new HashMap<Character,Integer>();
        genom.put('A',1);
        genom.put('C',2);
        genom.put('G',3);
        genom.put('T',4);
        
        int [] answer = new int[size_p];
        
        int [][] occurance = new int[size_s][4];
        
        for(int i=0;i<size_s;i++){
            char c = S.charAt(i);
            int val = genom.get(Character.valueOf(c));
            occurance[i][val-1] = 1;
        }
        
        for(int i=1;i<size_s;i++){
            for(int j=0;j<4;j++){
                occurance[i][j] += occurance[i-1][j];
            }
        }
        
        for(int i=0;i<size_p;i++){
            int start = P[i];
            int end = Q[i];
            if(end==start) {
                char c = S.charAt(start);
                int val = genom.get(Character.valueOf(c));
                answer[i] = val;
                continue;
            }
            for(int j=0;j<4;j++){
                
                if(start == 0 ) {
                    if(occurance[end][j] > 0 && occurance[end][j] - occurance[start][j] >= 0) {
                        answer[i] = j+1;
                        break;
                    }
                }
                else if(occurance[end][j] - occurance[start-1][j] > 0){
                    answer[i] = j+1;
                    break;
                }
            }
        }
        
        return answer;
        
    }
}

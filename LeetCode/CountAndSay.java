class Solution {
    public String countAndSay(int n) {
        String answer = "1";
        
        if(n==1){
            return "1";
        }
        for(int i=1;i<n;i++){
            int count = 1;
            int size = answer.length();
            StringBuilder sb = new StringBuilder();
            int j;
            for(j=1;j<size;j++){ 
                if(answer.charAt(j) == answer.charAt(j-1)) count++;
                else {
                    sb.append(count + "" + answer.charAt(j-1));
                    count = 1;
                }
            }
            if(j == size) sb.append(count + "" + answer.charAt(j-1));
            answer = sb.toString();
        }
        return answer;
    }
}

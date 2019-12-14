class Solution {
    public String longestPalindrome(String s) {
        int maxLength = 0;
        String answer = "";
        int len = s.length();
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                String subStr = s.substring(i, j+1);
                if(j-i+1>maxLength && isPalindrom(subStr)){
                   maxLength = j-i+1;
                   answer = subStr;    
                }
            }
        }
        
        return answer;
    }
    
    public boolean isPalindrom(String s) {
        int i = 0, j = s.length()-1;
        //System.out.println(s);
        while(i<=j){
            //System.out.println(i + " " + j);
            if(s.charAt(i)!=s.charAt(j))
                return false;
            i++;
            j--;
        }
        
        return true;
    }
}

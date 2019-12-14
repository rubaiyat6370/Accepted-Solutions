class Solution {
    public String longestPalindrome(String s) {
        int maxLength = 0;
        String answer = "";
        int len = s.length();
        for(int i=0;i<len;i++){
            String s1 = increaseLength(s,i,i);
            String s2 = increaseLength(s,i,i+1);
            
            if(s1.length()>=s2.length()) {
                if(s1.length() > answer.length()) {
                    answer = s1;
                }
            } else {
                if(s2.length() > answer.length()) {
                    answer = s2;
                }
            }
        }
        
        return answer;
    }
    
    public String increaseLength(String s, int start, int end) {
        int len = s.length();
        
        while(end>=start && end<len && start>=0) {
            if(s.charAt(start) != s.charAt(end)) {
                break;
            }
            start--;
            end++;

        }
        
        return s.substring(start+1,end);
    }
}

/**
"babad"
""
"a"
"aaaaaa"
**/

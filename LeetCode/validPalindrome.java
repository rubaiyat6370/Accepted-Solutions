class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        int j = len - 1, i = 0;
        boolean isPalindrome = true;
        while(i<=j){
            int posA = s.charAt(i) - '0';
            int posB = s.charAt(j) - '0';
            
            if(isValid(posA) && isValid(posB)) {
                if(posA < 49 && !isNumber(posA)) posA = posA + 32;
                if(posB < 49 && !isNumber(posB)) posB = posB + 32;
                if(posA != posB) {
                    isPalindrome = false;
                    break;
                } else {
                    i++;
                    j--;
                }
            }
            if(!isValid(posA)) i++;
            if(!isValid(posB)) j--;
        }
        return isPalindrome;
    }
    
    boolean isValid(int a) {
        if(isAlpha(a) || isNumber(a)) return true;
        return false;
    }
    
    boolean isAlpha(int a) {
        if((a >= 17 && a <= 42) || (a >=49 && a <= 74)) return true;
        return false;
    }
    
    boolean isNumber(int a) {
        if(a >= 0 && a <= 9) return true;
        return false;
    }
}

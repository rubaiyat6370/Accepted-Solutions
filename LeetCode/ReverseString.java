class Solution {
    public void reverseString(char[] s) {
        if(s.length == 0) return;
        int len = s.length - 1;
        
        for (int i = 0; i<= len/2;i++) {
            char temp = s[i];
            s[i] = s[len - i];
            s[len-i] = temp;
        }
    }
}

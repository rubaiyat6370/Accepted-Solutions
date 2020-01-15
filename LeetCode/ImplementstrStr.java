class Solution {
    public int strStr(String haystack, String needle) {
        int haylen = haystack.length();
        int needleLen = needle.length();
        
        if (needleLen == 0) return 0;
        
        if(needleLen > haylen) return -1;
        
        int j = 0, i = 0, index = -1;
        
        for(i = 0 ;i< haylen; i++){
            
            if(j<needleLen && haystack.charAt(i) == needle.charAt(j)) {
                if(index == -1) index = i;
                j++;
                
                if(index != -1 && j == needleLen) break; 
            }
            else if(index != -1 && j < needleLen) {
                j = 0;
                i = index;
                index = -1;
            }
            
        }
        
        if(index != -1 && j < needleLen) index = -1;
        
        return index;
    }
}

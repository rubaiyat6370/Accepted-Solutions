class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len = strs.length;
        if(len==0) return "";
        boolean isMatch = true;
        int count = 0;
        while(isMatch) {
            int i=0;
            if(count >= strs[i].length()) break;
            char start = strs[i].charAt(count);
            for(i = 1;i<len;i++) {
                if(count >= strs[i].length() || start != strs[i].charAt(count)){
                    isMatch = false;
                    break;
                }
            }
            if(isMatch) count++;
            else break;
        }
        return count>0 ? strs[0].substring(0,count) : "";
    }
}

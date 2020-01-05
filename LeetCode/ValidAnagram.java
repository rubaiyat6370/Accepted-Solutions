class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int [] arr = new int[26];
        for(int i=0;i<s.length();i++) {
            int pos = s.charAt(i) - 'a';
            arr[pos]++;
        }
        
        for(int i=0;i<t.length();i++){
            int pos = t.charAt(i) - 'a';
            if(arr[pos]==0) return false;
            else arr[pos]--;
        }
        return true;
    }
}

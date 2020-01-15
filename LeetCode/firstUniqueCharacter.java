class Solution {
    public int firstUniqChar(String s) {
        int [][]arr = new int[26][2];
        int len = s.length();
        for(int i=0;i<len;i++) {
            int pos = s.charAt(i) - 'a';
            if(arr[pos][0]==0) arr[pos][1] = i;
            arr[pos][0]++;
        }
        int minIdx = -1;
        for(int i = 0; i<26;i++) 
            if(arr[i][0] == 1) {
                if(arr[i][1] < minIdx || minIdx == -1) 
                    minIdx = arr[i][1];
            } 
        
        return minIdx;
    }
}

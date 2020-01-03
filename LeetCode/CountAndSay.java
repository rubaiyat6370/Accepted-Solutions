class Solution {
    public String countAndSay(int n) {
        String answer = "1";
        
        if(n==1){
            return "1";
        }
        
        for(int i=1;i<n;i++){
            HashMap<Character,Integer> map = new HashMap<Character,Integer>();
            int size = answer.length();
            StringBuilder sb = new StringBuilder();
            for(int j=0;j<size;j++){
                //char c = 
                if(map.containsKey(answer.charAt(j))){
                    int count = map.get(answer.charAt(j));
                    map.put(answer.charAt(j), count + 1);
                }else {
                    if(!map.isEmpty()) {
                        sb.append(map.get(answer.charAt(j-1)));
                        sb.append(answer.charAt(j-1));
                        map.clear();
                    }
                    map.put(answer.charAt(j),1);
                }
            }
            if(!map.isEmpty()) {
                sb.append(map.get(answer.charAt(size-1)));
                sb.append(answer.charAt(size-1));
                //map.clear();
            }
            
            answer = sb.toString();
        }
        return answer;
    }
}

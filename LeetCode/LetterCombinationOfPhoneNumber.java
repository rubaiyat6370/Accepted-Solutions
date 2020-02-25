class Solution {
    private String[] list = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private List<String> answer;
    private String input;
    public List<String> letterCombinations(String digits) {
        answer = new ArrayList<String>();
        input = digits;
        combination(0,new StringBuilder());
        return answer;
    }
    
    public void combination(int starti, StringBuilder sb) {
		if(sb.toString().length() == input.length() && input.length()!=0) {
			answer.add(sb.toString());
			return;
		}
		
		for(int i = starti; i<input.length();i++) {
            int pos = input.charAt(i) - '0';
			for(int j=0;j<list[pos].length();j++) {
                sb.append(list[pos].charAt(j)); //the list for char 2 starts from 0
                combination(i+1,sb);
                sb.setLength(sb.length()-1);
			}
		}
	}
}

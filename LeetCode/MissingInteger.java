class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int answer = 0;
        for(int i=0;i<len;i++){
            answer = answer^nums[i];
            answer = answer^(i+1);
        }
        return answer;
    }
}

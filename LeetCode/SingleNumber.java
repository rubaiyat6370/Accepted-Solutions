class Solution {
    public int singleNumber(int[] nums) {
        int len = nums.length;
        int answer = 0;
        for(int i=0;i<len;i++){
            answer = answer^nums[i];
        }
        return answer;
    }
}

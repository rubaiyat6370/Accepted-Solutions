public class Solution {
    public void SortColors(int[] nums) {
        int start = 0, end = nums.Length -1;

        for(int i = 0;i<= end;i++){
            if(nums[i] == 0) {
                nums[start++] = 0;
            }
            else if(nums[i] == 2) {
                while(end > i && nums[end] == 2) {
                    end--;
                }
                
                if(nums[end] == 0) nums[start++] = 0;
                nums[end--] = 2;
            }

        }
        
        for(int i = start;i<=end;i++){
            nums[i] = 1;
        }
    }
}

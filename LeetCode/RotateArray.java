class Solution {
    public void rotate(int[] nums, int k) {
        int currentPosition = 0, newPosition = 0;
        int count = 0;
        int valueToPass;
        int length = nums.length;
        
        for(int start = 0;count<length ;start++){
            valueToPass = nums[start];
            currentPosition = start;
            while(true){
                newPosition = (currentPosition + k) % length;
                //System.out.println("cur: " + currentPosition + " newPosition: " + newPosition + " valueToPass: " + valueToPass);
                int temp = nums[newPosition];
                nums[newPosition] = valueToPass;
                //System.out.println(nums[newPosition]);
                valueToPass = temp;
                count++;
                if(newPosition == start) break;
                currentPosition = newPosition;
                
                if(count>=length) return;
            }
        }
    }
}

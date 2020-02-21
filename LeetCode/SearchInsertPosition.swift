class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        let len = nums.count
        var left = 0, right = len - 1, mid = 0
        
        while(left <= right) {
            mid = (left+right)/2
            if nums[mid] == target {
                return mid
            } else if nums[mid] < target {
                if (mid + 1 < len && nums[mid+1] > target) || (mid + 1 == len){
                    return mid + 1
                } else {
                    left = mid + 1
                }
                
            } else {
                if mid - 1 >= 0 && nums[mid-1] < target {
                    return mid
                } else {
                    right = mid - 1
                }
                
            }
            
        }
        return mid
    }
}

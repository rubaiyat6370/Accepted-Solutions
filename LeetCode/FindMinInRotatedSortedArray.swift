/*
Find Minimum in Rotated Sorted Array II
*/
class Solution {
    func findMin(_ nums: [Int]) -> Int {
        return find(0, nums.count-1, nums)
    }
    
    func find(_ l: Int, _ r: Int, _ nums: [Int]) -> Int {
        var left = l, right = r, mid = 0, minLeft = 0, minRight = 0

        if left >= right {
            if right >= 0 {
                return nums[right]
            } else {
                return nums[left]
            }
        
        }
        if nums[left] < nums[right] {
            return nums[left]
        }
        
        mid = left + (right-left)/2

        if nums[left] < nums[mid] {
            minLeft = nums[left]
        } else { 
            let lval = find(left,mid-1,nums)
            minLeft = lval < nums[mid] ? lval : nums[mid]
        } 

        if nums[mid] < nums[right] {
            minRight = nums[mid]
        } else {
            let lval = find(mid + 1,right,nums)
            minRight = lval < nums[mid] ? lval : nums[mid]
        }
        
        return minLeft < minRight ? minLeft : minRight
    }
}

/*
[1,3,5]
[4,5,6,7,0,1,2]
[2,2,2,0,1]
[2,2,2,2,1,2,2]
[1,2,1]
*/

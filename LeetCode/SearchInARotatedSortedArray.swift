class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        if nums.count == 0 {
            return -1
        }
        var left = 0, right = nums.count - 1
        var mid = 0
        while(left <= right && nums[left] > nums[right]) {
            mid = (left + right)/2
            
            if nums[mid] == target {
                return mid
            }
            if nums[left] > nums[mid] {
                right = mid - 1
            }
            else {
                left = mid + 1
            }
        }
        
        let v1 = search(left:0, right: mid,nums: nums,target: target)
        if v1 != -1 {
            return v1
        }
        return search(left:mid + 1, right: nums.count - 1,nums: nums,target: target)
    }
    
    func search(left: Int, right: Int, nums: [Int], target: Int) -> Int {
        var l = left, r = right
        while l <= r {
            let mid = (l + r)/2
            if nums[mid] == target {
                return mid
            }
            
            if nums[mid] < target {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        return -1
    }
}

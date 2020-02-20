class Solution {
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        let length = nums.count
        if length == 0 {
            return [-1, -1]
        }
        let start = searchStart(l: 0, r: length - 1, nums: nums, target: target)
        print(start)
        if start == -1 {
            return [-1, -1]
        }
        let end = searchEnd(l: 0, r: length - 1, nums: nums, target: target)
        print(end)
        return [start,end]
    }
    
    func searchStart(l: Int, r: Int, nums: [Int], target: Int) -> Int {
        var left = l, right = r
        var mid = 0
        var pos = -1
        while(left<=right) {
            
            mid = (left+right)/2
            print("left: \(left), right: \(right)")
            if nums[mid] == target {
                if mid - 1 >= 0 && nums[mid - 1] == target{
                    right = mid - 1
                    pos = mid - 1
                } else {
                    return mid
                }
            }else if nums[mid] < target {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        return pos
    }
    
    func searchEnd(l: Int, r: Int, nums: [Int], target: Int) -> Int {
        var left = l, right = r
        var mid = 0
        var pos = -1
        while(left<=right) {
            mid = (left+right)/2
            
            if nums[mid] == target {
                if mid + 1 < nums.count && nums[mid + 1] == target{
                    left = mid + 1
                    pos = mid + 1
                } else {
                    return mid
                }
            }else if nums[mid] < target {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        return pos
    }
}

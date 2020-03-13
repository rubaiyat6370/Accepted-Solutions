class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        var one = 0, maxCount = 0, i = 0
        while i < nums.count {
            var count = 0
            while i < nums.count && nums[i] == 1{
                count += 1
                maxCount = max(maxCount, count)
                i += 1
            }
            i += 1
        }
        return maxCount
    }
}

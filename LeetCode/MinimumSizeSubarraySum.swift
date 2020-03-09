class Solution {
    func minSubArrayLen(_ s: Int, _ nums: [Int]) -> Int {
        var start = 0, end = 0, sum = 0, count = Int.max
        
        while end < nums.count {
            sum = sum + nums[end]
            
            while sum >= s {
                var currentCount = end - start + 1
                if currentCount < count {
                    count = currentCount
                }
                sum = sum - nums[start]
                start += 1
            }
            end += 1
        }
        return count < Int.max ? count : 0
    }
}

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var maxEnd = nums[0]
        var maxNow = nums[0]
        
        var i = 1
        
        while i < nums.count {
            maxEnd = max(maxEnd + nums[i], nums[i])
            maxNow = max(maxNow, maxEnd)
            i += 1
        }
        
        return maxNow
    }
}

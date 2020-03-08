class Solution {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var start = 0, end = 0, sum: Double = 0.0, maxAvg = Double(-18446744073709551616)
        
        while end < nums.count {
            sum = sum + Double(nums[end])
            
            if end >= k - 1 {
                if sum/Double(k) > maxAvg {
                    maxAvg = sum/Double(k)
                }
                sum -= Double(nums[start])
                start += 1
            }
            
            end += 1
        }
        return maxAvg 
    }
}

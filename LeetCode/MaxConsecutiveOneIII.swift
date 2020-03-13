class Solution {
    func longestOnes(_ A: [Int], _ K: Int) -> Int {
        var map = [Int: Int]()
        var start = 0, end = 0, maxLength = 0, maxCount = 0
        
        while end < A.count {
            if map[A[end]] != nil {
                var value = map[A[end]]!
                map[A[end]] = value + 1
            } else {
                map[A[end]] = 1
            }
            
            if map[1] != nil {
                maxCount = max(map[1]!, maxCount)
            }
            
            if end - start + 1 - maxCount > K {
                var value = map[A[start]]!
                map[A[start]] = value - 1
                start += 1
            }
            
            maxLength = max(maxLength, end - start + 1)
            end += 1
        }
        return maxLength
    }
}

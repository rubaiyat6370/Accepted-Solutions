class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var set = Set<Character>()
        var start = 0, end = 0, maxLength = 0
        let arr = Array(s)
        while end < arr.count {
            if !set.contains(arr[end]) {
                set.insert(arr[end])
                end += 1
            } else {
                set.remove(arr[start])
                start += 1
            }
            maxLength = max(maxLength, end-start)
        }
        return maxLength
    }
}

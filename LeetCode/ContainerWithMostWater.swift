class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxArea = 0
        var start = 0, end = height.count - 1
        while start < end {
            let area = (end - start) * getMin(height[end],height[start])
            if area > maxArea {
                maxArea = area
            } 
            
            if height[start] < height[end] {
                start += 1
            } else {
                end -= 1
            }
        }
        return maxArea
    }
    
    func getMin(_ num1: Int, _ num2: Int) -> Int {
        return num1 < num2 ? num1 : num2
    }
}

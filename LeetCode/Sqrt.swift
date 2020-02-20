class Solution {
    func mySqrt(_ x: Int) -> Int {
        var left = 1, right = x, mid = 0
        
        while(left <= right) {
            mid = (left+right)/2
            let sqr = mid*mid
            if(sqr == x) {
                return mid
            } else if sqr < x {
                if (mid+1)*(mid+1) > x {
                    return mid
                } else {
                    left = mid + 1
                }
                
            } else {
                right = mid - 1
            }
        }
        return mid
    }
}

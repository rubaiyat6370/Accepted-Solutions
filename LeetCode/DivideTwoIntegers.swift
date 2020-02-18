class Solution {
    func divide(_ dividend: Int, _ divisor: Int) -> Int {
        let sign = (dividend < 0) == (divisor < 0) ? 1 : -1
        if dividend == -2147483648 && divisor == -1 {
            return 2147483647
        } 
        if divisor == 1 {
            return dividend
        }
        if divisor == -1 {
            return -dividend
        }
        
        var dividendA: Int = {
            return dividend < 0 ? -dividend : dividend
        }()
        var divisorA: Int = {
            return divisor < 0 ? -divisor : divisor
        }()
        
        if divisorA > dividendA || dividendA == 0 {
            return 0
        } else if divisorA == dividendA {
            return sign*1
        }
        var left = 0, right = dividendA
        
        while left < right {
            let mid = (left + right)/2
            let result = divisorA*mid
            if result > dividendA {
                right = mid
            } else {
                left = mid + 1
            }
        }
        return sign*(left-1)
    }
}

class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
        var answer = 1.00, i = 2, N = n
        let sign = n < 0 ? false : true
        
        if n == 0  || x == 1 {
            return 1
        }
        
        if n < 0 {
            N = -n
        }
        var sqr = x
        while true {
            if N == 0 {
                break
            }
            
            if N == 1 {
                answer = answer * x
                break
            }
            while(i<=N) {
                sqr = sqr * sqr
                i = i*2
            }
            answer = answer * sqr
            sqr = x
            N = N - i/2
            i = 2
        }
        
        return n < 0 ? 1/answer : answer
    }
}

/**
2.00000
10
2.10000 
3
2.00000 
-2
1
-2147483648
-1
-2147483648
1
2147483647
-1
2147483647
-100
2147483647
100
2147483647
-100
-2147483648
100
-2147483648
0
0
-1
2
2
-1

**/

func beautifulPairs(A: [Int], B: [Int]) -> Int {

    var a = [Int](repeatElement(0, count: 1001))
    var b = [Int](repeatElement(0, count: 1001))

    var count = 0
    for i in 0..<A.count {
        a[A[i]]+=1
        b[B[i]]+=1
        if a[A[i]] > 0 && b[A[i]] > 0 {
            a[A[i]]-=1
            b[A[i]]-=1
            count+=1
        }

        if a[B[i]] > 0 && b[B[i]] > 0 {
            a[B[i]]-=1
            b[B[i]]-=1
            count+=1
        }
    }
   
    return count < A.count ? count + 1 : count - 1
}

Sample Input
https://hr-testcases-us-east-1.s3.amazonaws.com/16828/input02.txt?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1577738568&Signature=cABa4ytDMHKP%2FnZc5UR7pv1H0jE%3D&response-content-type=text%2Fplain
Sample output 203

1 
1 
1

0

class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        var numbers: [Int] = nums
        numbers.sort()
        var answer = [[Int]]()
        
        for index in numbers.indices {
            let target = -numbers[index]
            if index - 1 >= 0 && numbers[index - 1] == numbers[index] {
                continue
            }
            var l = index + 1, r = numbers.count - 1
            
            while l < r {
                
                if numbers[l] + numbers[r] == target {
                    if answer.count > 0 {
                        let last: [Int] = answer[answer.count - 1]
                        if last[0] == numbers[index] && last[1] == numbers[l] && last[2] == numbers[r] {    
                            l += 1
                        } else {
                            answer.append([numbers[index], numbers[l], numbers[r]])
                            l += 1
                        }
                    } else {
                        answer.append([numbers[index], numbers[l], numbers[r]])
                        l += 1
                    }
                    
                } else {
                    if numbers[l] + numbers[r] < target {
                        l += 1
                    } else {
                        r -= 1
                    }
                }
            }
        }
        
        return answer
    }
}

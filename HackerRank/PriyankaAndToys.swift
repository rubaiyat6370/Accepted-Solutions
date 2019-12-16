import Foundation

// Complete the toys function below.
func toys(w: [Int]) -> Int {
    var input  = w
    input.sort()
    var min = input[0]
    var max = min + 4
    var container = 1;
    for var i in 0..<input.count {
        if input[i] <= max {
            i+=1;
        } else {
            container+=1
            min = input[i]
            max = min + 4
        }
    }
    return container
}

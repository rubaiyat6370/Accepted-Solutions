class Solution {
    func totalFruit(_ tree: [Int]) -> Int {
        var start = 0, end = 0, maxCount = 0
        var map = [String: Int]()
        
        while end < tree.count {
            var key = "\(tree[end])"
            if map[key] != nil {
                let value: Int = map[key]!
                map[key] = value + 1
            } else {
                map[key] = 1
            }
            while map.count > 2 {
                key = "\(tree[start])"
                let value: Int = map[key]!
                map[key] = value - 1
                if map[key] == 0 {
                    map.removeValue(forKey: key)
                }
                start += 1
            }
            
            //print(map)
            
            maxCount = max(end - start + 1, maxCount)
            end += 1
        }
        
        return maxCount
    }
}

/**
[1,2,1]
[1,2,3,2,2]
[3,3,3,1,2,1,1,2,3,3,4]
[]
[1]
[1,0,1,4,1,4,1,2,3]
**/

import UIKit

class Heap<T> {
    var heap = Array<T>()
    typealias comparator = (T,T) -> Bool
    var compare: comparator

    init(closure: @escaping comparator) {
        self.compare = closure
    }

    func isEmpty() -> Bool {
        if heap.count > 0 {
            return false
        }
        return true
    }

    func insert(value: T) {
        heap.append(value)
        bubbleUp()
    }

    func swapElement(i1: Int, i2: Int) {
        let TempValue = heap[i1]
        heap[i1] = heap[i2]
        heap[i2] = TempValue
    }

    func bubbleUp() {
        var child = heap.count - 1
        var parent = (child - 1)/2

        while parent >= 0 {
            if compare(heap[child], heap[parent]) {
                swapElement(i1: parent, i2: child)
                child = parent
                parent = (child - 1)/2
            } else {
                return
            }
        }
    }

    func bubbleDown(parent: Int) {
        var minIndex = 0
        let parent = parent
        let leftChild = (parent * 2) + 1
        guard leftChild <= heap.count - 1 else {
            return
        }

        let rightChild = (parent * 2) + 2
        if rightChild > heap.count - 1 {
            minIndex = leftChild
        } else {
            minIndex = compare(heap[leftChild], heap[rightChild]) ? leftChild : rightChild
        }
        if compare(heap[minIndex], heap[parent]) {
            swapElement(i1: minIndex, i2: parent)
            bubbleDown(parent: minIndex)
        }
    }

    func extract() -> T? {
        if !isEmpty() {
            let value = heap[0]
            heap[0] = heap[heap.count-1]
            heap.remove(at: heap.count - 1)
            bubbleDown(parent: 0)
            return value
        } else {
            return nil
        }
    }

    func description() -> String {
        var str = ""
        for item in heap {
            str.append(contentsOf: " \(item)")
        }
        return str
    }
}

let heap = Heap<Int> { (a, b) -> Bool in
    a < b
}

heap.insert(value: 10)
heap.insert(value: 4)
heap.insert(value: 8)
heap.insert(value: 5)
heap.insert(value: 12)
heap.insert(value: 0)
heap.insert(value: 3)

print(heap.description())

while !heap.isEmpty() {
    print(heap.extract()!)
}



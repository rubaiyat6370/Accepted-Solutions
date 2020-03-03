/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }
        
        var p1: ListNode? = l1, p2: ListNode? = l2
        let start: ListNode?
        var current: ListNode?
    
        if p1!.val <= p2!.val {
            start = p1
            p1 = p1?.next
        } else {
            start = p2
            p2 = p2?.next
        } 
        current = start
        while p1 != nil && p2 != nil {
            if p1!.val <= p2!.val {
                current?.next = p1
                p1 = p1?.next
            } else {
                current?.next = p2
                p2 = p2?.next
            } 
            current = current?.next
        }
        
        if p1 != nil {
            current?.next = p1
        } else {
            current?.next = p2
        }
        return start
    }
}

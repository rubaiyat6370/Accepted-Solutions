/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode n1 = null, n2 = head;
        int count = 0;
        
        while(n2.next!=null) {
            count++;
            if(count==n){
                n1 = head;
            } else if(n1!=null) {
                n1 = n1.next;
            }
            n2 = n2.next;
        }
        if(n1==null) {
            head = head.next;
        }
        else {
            n1.next = n1.next.next;
        } 
            
        return head;
    }
}

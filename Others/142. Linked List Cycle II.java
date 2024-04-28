/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Map<ListNode,Integer> map = new HashMap<>();
        ListNode cur = head;
        while(cur != null){
            if(map.containsKey(cur)){
                return cur;
            }
            map.put(cur, 1);
            cur = cur.next;
        }
        map.clear();
        return null;
    }
}
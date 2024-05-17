class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        List<List<Integer>> list = new ArrayList<>();
        ListNode cur = head;
        int size = 0;
        while(cur != null){
            cur = cur.next;
            size++;
        }
        cur = head;
        for(int i = 0; i < size; i+=k){
            List<Integer> temp = new ArrayList<>();
            for(int j = i; j < i+k && j < size && cur != null; j++){
                temp.add(cur.val);
                cur = cur.next;
            }
            if(temp.size() == k) {
                Collections.reverse(temp);
                list.add(temp);
            }
            else if(temp.size() > 0)list.add(temp);
        }
        ListNode newHead = new ListNode();
        cur = newHead;
        for(int i = 0; i < list.size(); i++){
            for(int j = 0; j < list.get(i).size(); j++){
                cur.val = list.get(i).get(j);
                if(i == list.size()-1 && j == list.get(i).size() - 1){
                    continue;
                }
                cur.next = new ListNode();
                cur = cur.next;
            }
        }
        return newHead;
    }
}
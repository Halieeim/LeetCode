class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode* cur = head, *prev = new ListNode();
        prev->next = head;
        while(cur){
            if(cur->val == val && prev->next != head){
                prev->next = cur->next;
            }
            else if(cur->val == val && prev->next == head){
                head = head->next;
                prev->next = head;
            }
            else prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
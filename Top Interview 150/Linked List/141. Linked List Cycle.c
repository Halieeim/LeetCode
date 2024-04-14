/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return false;
    struct ListNode* current = head;
    struct ListNode* next = head;
    while(next && next->next){
        current = current->next;
        next = next->next->next;
        if(next == current) return true;
    }
    return false;
}
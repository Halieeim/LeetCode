/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode * current = head;
    struct ListNode * temp = head;
    struct ListNode * t = NULL;
    current = current->next;
    while(current != NULL){
        t = current->next;
        if(temp == head){
            temp->next = NULL;
            current->next = temp;
        }
        else{
            current->next = temp;
        }
        temp = current;
        current = t;
    }
    return temp;
}
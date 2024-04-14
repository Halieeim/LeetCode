/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head){
    if(head == NULL)
        return head;
    struct ListNode* tail = head;
    struct ListNode* middle = head;
    struct ListNode* prev = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    prev->next = head;
    while(tail != NULL && tail->next != NULL){
        prev = prev->next;
        middle = middle->next;
        tail = tail->next->next;
    }
    if(tail == head)
        head = NULL;
    else
        prev->next = middle->next;
    // free(middle);
    return head;
}
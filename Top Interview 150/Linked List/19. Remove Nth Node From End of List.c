/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL)
        return head;
    struct ListNode* current = (struct ListNode*)malloc(sizeof(struct ListNode));
    current->next = head;
    struct ListNode* base = head;
    int size = 0;
    while(base != NULL){
        size++;
        base = base->next;
    }
    base = current;
    printf("%d", size);
    size -= n;
    int counter = 0;
    while((current->next != NULL) && (counter < size)){
        counter++;
        current = current->next;
    }
    if(current->next)
        current->next = current->next->next;
    else
        current->next = NULL;
    return base->next;
}
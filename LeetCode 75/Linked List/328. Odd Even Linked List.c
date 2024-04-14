/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL)
        return head;
    struct ListNode* oddPtr = head;
    struct ListNode* temp = head->next;
    struct ListNode* evenPtr = head->next;
    int i = 0;
    if(evenPtr == NULL)
        return head;
    while((oddPtr->next->next != NULL) && (evenPtr->next->next != NULL)){
        oddPtr->next = oddPtr->next->next;
        oddPtr = oddPtr->next;
        evenPtr->next = evenPtr->next->next;
        evenPtr = evenPtr->next;
    }
    if(evenPtr->next){
        oddPtr->next = evenPtr->next;
        oddPtr->next->next = temp;
        evenPtr->next = NULL;
    }
    else{
        oddPtr->next = temp;
    }
    return head;
}
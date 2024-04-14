/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode* current = head;
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->val = -5000000;
    prev->next = head;
    struct ListNode* Next = current->next;
    struct ListNode* base = head;
    while(Next){
        if(current->val != Next->val){
            prev = prev->next;
        }
        else{
            while(Next && current->val == Next->val){
                current = current->next;
                Next = Next->next;
            }
            if(prev->val == -5000000) base = Next;
            prev->next = Next;
        }
        current = current->next;
        Next = Next ? Next->next : NULL;
    }
    return base;
}
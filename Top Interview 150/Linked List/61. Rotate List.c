/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* temp = head;
    int size = 0;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    k %= size;
    struct ListNode* current;
    for(int i = 0; i < k; i++){
        current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        current->next->next = head;
        head = current->next;
        current->next = NULL;
    }
    return head;
}
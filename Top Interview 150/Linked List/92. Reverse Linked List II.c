/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(head == NULL || right == left){
        return head;
    }
    
    
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    // Find the node before the left-th node
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    struct ListNode* current = prev->next;
    struct ListNode* tail = current;
    struct ListNode* next = NULL;

    // Reverse the sublist from left to right
    for (int i = left; i < right; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    // If left is not 1, then return the original head
    if (left != 1) {
        return head;
    } else {
        return dummy->next;
    }
}
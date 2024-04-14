// /**
//  * Definition for a Node.
//  * struct Node {
//  *     int val;
//  *     struct Node *next;
//  *     struct Node *random;
//  * };
//  */

struct Node* copyRandomList(struct Node* head) {
    if(head == NULL)
        return NULL;
    struct Node* current = head;
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    while(current != NULL){
        struct Node* n = (struct Node*)calloc(1, sizeof(struct Node));
        n->val = current->val;
        n->next = NULL;
        n->random = NULL;
        if(newHead == NULL){
            newHead = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        current = current->next;
    }
    current = head;
    tail = newHead;
    while(current != NULL){
        struct Node* ptr = newHead;
        struct Node* newPtr = head;
        int i = 0;
        while(newPtr != NULL){
            if(current->random != newPtr){
                newPtr = newPtr->next;
                i++;
            }
            else
                break;
        }
        int j = 0;
        printf("%d ",i);
        if(current->random != NULL){
            while((ptr != NULL) && j != i){
                ptr = ptr->next;
                j++;
            }
            tail->random = ptr;
        }
        tail = tail->next;
        current = current->next;
    }
    return newHead;
}
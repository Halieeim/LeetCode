/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;
    struct ListNode* current1 = list1;
    struct ListNode* current2 = list2;
    int size1 = 0, size2 = 0;
    while(current1){
        size1++;
        current1 = current1->next;
    }
    while(current2){
        size2++;
        if(current2->next == NULL) {
            current2->next = list1;
            break;
        }
        current2 = current2->next;
    }
    int total_size = size1 + size2;
    int* arr = (int*)malloc(total_size * sizeof(int));
    current2 = list2;
    int i = 0;
    while(current2){
        arr[i] = current2->val;
        i++;
        current2 = current2->next;
    }
    qsort(arr,total_size, sizeof(int), cmp);
    i = 0;
    current2 = list2;
    while(current2){
        current2->val = arr[i];
        i++;
        current2 = current2->next;
    }
    return list2;
}
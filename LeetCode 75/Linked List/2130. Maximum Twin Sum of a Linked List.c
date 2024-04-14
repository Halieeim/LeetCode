/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head){
    int max = INT_MIN, size = 0, i = 0;
    struct ListNode* current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    current = head;
    while(current != NULL){
        arr[i] = current->val;
        current = current->next;
        i++;
    }
    for(i = 0; i < size; i++){
        int sum = arr[i] + arr[size-i-1];
        if(sum > max)
            max = sum;
    }
    free(arr);
    return max;
}
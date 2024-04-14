struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* newList = NULL;
    struct ListNode* tail = newList;
    int carry = 0, i = 0;
    while(l1 || l2 || carry){
        int d1 = l1 ? l1->val : 0;
        int d2 = l2 ? l2->val : 0;
        int sum = d1 + d2 + carry;
        int d = sum % 10;
        carry = sum / 10;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = d;
        newNode->next = NULL;
        if(i == 0){
            newList = newNode;
            tail = newList;
            i++;
        }
        else{
            tail = newList;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = newNode;
        }
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return newList;
}
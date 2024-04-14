typedef struct node{
    int value;
    int index;
    char *key;
    struct node *next;
}node;

node *head = NULL;

node* find(int indx){
    static node *ptr = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    
    node *current = head;
    while (current != NULL)
    {
        if(current->index == indx){
            ptr = current;
            return ptr;
        }
        current = current->next;
    }
    free(current);
    return NULL;
}

void dictAdd(char k[], int v, int indx){
    // node* flag = find(k);
    // if(flag != NULL){
    //     (*flag).value++; 
    // }
    // else{
    node *n = (node*)calloc(1,sizeof(node));
    n->key = k;
    n->value = v;
    n->index = indx;
    n->next = head;
    head = n;
    // }
    // free(flag);
}

char * intToRoman(int num){
    dictAdd("I", 1, 1);
    dictAdd("IV", 4, 2);
    dictAdd("V", 5, 3);
    dictAdd("IX", 9, 4);
    dictAdd("X", 10, 5);
    dictAdd("XL", 40, 6);
    dictAdd("L", 50, 7);
    dictAdd("XC", 90, 8);
    dictAdd("C", 100, 9);
    dictAdd("CD", 400, 10);
    dictAdd("D", 500, 11);
    dictAdd("CM", 900, 12);
    dictAdd("M", 1000, 13);
    static char result[100] = {0};
    int i = 13;
    node *temp = find(i);
    result[0] = '\0';
    while(num > 0){
        if(num >= temp->value){
            num -= temp->value;
            strcat(result,temp->key);
        }else{
            i--;
            temp = find(i);
        }
    }
    free(temp);
    return result;
}
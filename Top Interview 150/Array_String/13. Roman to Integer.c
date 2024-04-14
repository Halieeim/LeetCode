typedef struct node{
    int value;
    char key;
    struct node *next;
}node;

node *head = NULL;

node* find(char k){
    static node *ptr = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    
    node *current = head;
    while (current != NULL)
    {
        if(current->key == k){
            ptr = current;
            return ptr;
        }
        current = current->next;
    }
    free(current);
    return NULL;
}

void dictAdd(char k, int v){
    // node* flag = find(k);
    // if(flag != NULL){
    //     (*flag).value++; 
    // }
    // else{
    node *n = (node*)calloc(1,sizeof(node));
    n->key = k;
    n->value = v;
    n->next = head;
    head = n;
    // }
    // free(flag);
}


int romanToInt(char * s){
    dictAdd('I', 1);
    dictAdd('V', 5);
    dictAdd('X', 10);
    dictAdd('L', 50);
    dictAdd('C', 100);
    dictAdd('D', 500);
    dictAdd('M', 1000);
    int result = 0, i;
    node *temp1 = NULL;
    node *temp2 = NULL;
    for(i = 0; s[i] != NULL; i++){
        temp1 = find(s[i]);
        if(s[i+1] != NULL){
            temp2 = find(s[i+1]);
            if (temp1->value >= temp2->value){
                result += temp1->value;
            }
            else{
                result -= temp1->value;
            }
        }
        else{
            result += temp1->value;
        }
    }
    return result;
}
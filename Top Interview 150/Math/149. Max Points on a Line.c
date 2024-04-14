typedef struct node{
    int value;
    double key;
    struct node *next;
}node;

node *head = NULL;

node* find(double k){
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

void dictAdd(double k){
    node* flag = find(k);
    if(flag != NULL){
        (*flag).value++; 
    }
    else{
        node *n = (node*)calloc(1,sizeof(node));
        n->key = k;
        (*n).value++;
        n->next = head;
        head = n;
    }
    // free(flag);
}

void freeDict(){
    node* current = head;

    while (current != NULL) {
        current->value = 0; // Store the next node before deallocating the current one
        current = current->next;       // Move to the next node
    }

}

int maxPoints(int** points, int pointsSize, int* pointsColSize){
    int max = 0, counter = 0;
    double slope;
    // compute all slopes
    for (int i = 0; i < pointsSize; i++)
    {
        for (int j = i+1; j < pointsSize; j++)
        {
            if((points[j][0] - points[i][0]) != 0){
                slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
            }
            else{
                slope = 5000;
            }
            dictAdd(slope);
        }
        node *iterator = head;
        while (iterator != NULL)
        {
            if(iterator->value > max)
                max = iterator->value;
            iterator = iterator->next;
        }
        free(iterator);
        freeDict();
        node *head = NULL;
    }
        
    return max+1;
}
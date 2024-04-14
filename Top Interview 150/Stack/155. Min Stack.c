//typedef struct MinStack MinStack;

typedef struct{
    int* stack;
    int* mins;
}MinStack;

MinStack* cur = NULL;
int idx = 0;

MinStack* minStackCreate() {
    idx = 0;
    MinStack* s = (MinStack*) calloc(1, sizeof(MinStack));
    s->stack = (int*) malloc(30000 * sizeof(int));
    s->mins = (int*) malloc(30000 * sizeof(int));
    cur = s;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    if(obj == NULL) return;
    obj->stack[idx] = val;
    if(idx == 0) obj->mins[idx] = val;
    else if(val < obj->mins[idx-1]){
        obj->mins[idx] = val;
    }
    else{
        obj->mins[idx] = obj->mins[idx-1];
    }
    idx++;
}

void minStackPop(MinStack* obj) {
    idx--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[idx-1];
}

int minStackGetMin(MinStack* obj) {
    printf("%d\n", idx);
    return obj->mins[idx-1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
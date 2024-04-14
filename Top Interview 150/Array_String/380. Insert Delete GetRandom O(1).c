typedef struct {
    int *nums;
    int capacity;
    int count;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    RandomizedSet* set = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    set->capacity = 15;
    set->nums = (int*)malloc(set->capacity * sizeof(int));
    set->count = 0;
    return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if(obj->count == obj->capacity){
        obj->capacity *= 2;
        obj->nums = (int*)realloc(obj->nums, obj->capacity * sizeof(int));
    }

    for(int i = 0; i < obj->count; i++){
        if(obj->nums[i] == val){
            return false;
        }
    }
    obj->nums[obj->count] = val;
    obj->count++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    for(int i = 0; i < obj->count; i++){
        if(obj->nums[i] == val){
            //swap
            obj->nums[i] = obj->nums[obj->count - 1];
            obj->count--;
            return true;
        }
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int idx = rand() % obj->count;
    return obj->nums[idx];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/
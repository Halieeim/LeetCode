typedef struct {
    int num;
    int pos;
} numPosType;

int cmp(const void* a, const void* b) {
    numPosType A = *(numPosType*) a;
    numPosType B = *(numPosType*) b;
    return A.num - B.num;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    numPosType numPosArr[numsSize];
    for(int i = 0; i < numsSize; i++) {
        numPosArr[i].pos = i;
        numPosArr[i].num = nums[i];
    }
    qsort(numPosArr, numsSize, sizeof(numPosType), cmp);
    for(int i = 0; i < numsSize - 1; i++) {
        if(numPosArr[i].num == numPosArr[i+1].num) {
            if(numPosArr[i+1].pos - numPosArr[i].pos <= k) {
                return true;
            } 
        }
    }
    return false;
}
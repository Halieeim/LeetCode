/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        res[i] = 1;
    }
    for(int i=1; i<numsSize; i++) {
        res[i] = res[i-1] * nums[i-1];
    }
    for(int i=numsSize-2; i>=0; i--) {
        nums[i] *= nums[i+1];
        res[i] *= nums[i+1];
    }
    return res;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* pos = (int*)calloc(2 , sizeof(int));
    int flag = 1;
    for(int i = 0; i < numsSize; i++){
        if((nums[i] == target) && flag){
            flag = 0;
            pos[0] = i;
            pos[1] = i;
        }
        else if(nums[i] == target){
            pos[1] = i;
        }
    }
    if(flag){
        pos[0] = -1;
        pos[1] = -1;
    }
    *returnSize = 2;
    return pos;
}
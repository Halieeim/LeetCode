/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(numsSize * sizeof(int));
    int sum = 0, counter = 0, temp;
    for(int i = 0; i < numsSize; i++){
        temp = target - nums[i];
        for(int j = 0; j < numsSize; j++){
            if(temp == nums[j] && i != j){
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }
    *returnSize = 2;
    return res;
}
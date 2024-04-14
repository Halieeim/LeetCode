/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int size, int target, int* returnSize){
    int* solution = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int* p1 = nums;
    int* p2 = nums + size - 1;
    while(1){
        if((*p1 + *p2) == target){
            solution[0] = p1 - nums + 1;
            solution[1] = p2 - nums + 1;
            break;
        }
        else if((*p1 + *p2) < target){
            p1++;
        }
        else{
            p2--;
        }
    }
    return solution;
}
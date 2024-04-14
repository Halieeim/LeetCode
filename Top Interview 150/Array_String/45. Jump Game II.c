int jump(int* nums, int numsSize){
    if(numsSize == 1)
        return 0;
    int target = numsSize-1, counter = 0;
    for(int i = 0; i < numsSize; i++){
        if(i + nums[i] >= target){
            counter++;
            target = i;
            i = -1;
        }
        if(target == 0) break;
    }
    return counter;
}
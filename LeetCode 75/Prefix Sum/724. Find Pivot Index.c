int pivotIndex(int* nums, int numsSize){
    int sum = 0, leftSum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    for(int i = 0; i < numsSize; i++){
        if(leftSum == (sum - leftSum - nums[i]))
            return i;
        else
            leftSum += nums[i];
    }
    return -1;
}
void moveZeroes(int* nums, int numsSize){
    int i,j = 0;
    int* temp = (int*)calloc(numsSize, sizeof(int));
    for(i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            temp[j] = nums[i];
            j++;
        }
    }
    for(int k = 0; k < numsSize; k++){
        nums[k] = temp[k];
    }
}
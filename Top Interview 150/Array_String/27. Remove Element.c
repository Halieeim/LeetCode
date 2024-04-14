int removeElement(int* nums, int numsSize, int val){
    int k = 0, n = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == val){
            k++;
        }
    }
    for(int i = 0; i < numsSize-k; i++){
        if(nums[i] == val){
            n++;
            while(nums[i] == nums[numsSize - n]){
                n++;
            }
            int temp = nums[i];
            nums[i] = nums[numsSize - n];
            nums[numsSize - n] = temp;
        }
    }
    return (numsSize - k);
}
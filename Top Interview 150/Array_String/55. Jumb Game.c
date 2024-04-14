bool canJump(int* nums, int numsSize){
    if(numsSize == 1)
        return true;
    int jumb = 1, flag = 0;
    for(int i = numsSize-2; i >= 0; i--){
        if(nums[i] >= jumb){
            jumb = 1;
            flag = 0;
        }
        else{
            flag = 1;
            jumb++;
        }
    }
    return flag?false:true;
}
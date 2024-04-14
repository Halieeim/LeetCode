int longestOnes(int* nums, int s, int k){
    int i, j = 0;
    for(i = 0; i < s; i++){
        if(nums[i] == 0) k--;
        if(k < 0){
            if(nums[j] == 0) k++;
            j++;
        }
    }
    return i - j;
}
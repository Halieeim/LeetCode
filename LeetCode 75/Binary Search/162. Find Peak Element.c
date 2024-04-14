int getMaxIdx(int* arr, int size){
    int max = INT_MIN, idx = 0;
    for(int i = 0; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
            idx = i;
        }
    }
    return idx;
}

int findPeakElement(int* nums, int size) {
    int idx = getMaxIdx(nums, size);
    if(size == 1) return 0;
    else if((idx == 0) || (idx == size-1)){
        return idx;
    }
    
    int i, j = 0 , k = 1;
    for(i = 2; i < size; i++){
        if(nums[k] >  nums[j] && nums[k] > nums[i]){
            return k;
        }
        k++;
        j++;
    }
    return 0;
}
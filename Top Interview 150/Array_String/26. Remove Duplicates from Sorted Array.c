int removeDuplicates(int* nums, int size){
    int k = 0, n = 0, i, j;
    // for(i = 0; i < numsSize; i++){
    //     for(j = 0; j < numsSize; j++){
    //         if((nums[i] == nums[j]) && (j != i)){
    //             k++;
    //         }
    //     }
    // }
    // printf("k = %d", k);
    // for(i = 0; i < numsSize-k; i++){
    //     for(j = 0; j < numsSize; j++){
    //         if((nums[i] == nums[j]) && (j != i)){
    //             n++;
    //             while(nums[i] == nums[numsSize - n]){
    //                 n++;
    //             }
    //             int temp = nums[j];
    //             nums[j] = nums[numsSize - n];
    //             nums[numsSize - n] = temp;
    //         }
    //     }
    // }
    // return (numsSize - k+1);
    
    // use nested for loop to find the duplicate elements in array  
    for ( i = 0; i < size; i ++)  
    {  
        for ( j = i + 1; j < size; j++)  
        {  
            // use if statement to check duplicate element  
            if ( nums[i] == nums[j])  
            {  
                // delete the current position of the duplicate element  
                for ( k = j; k < size - 1; k++)  
                {  
                    nums[k] = nums[k + 1];  
                }  
                // decrease the size of array after removing duplicate element  
                size--;  
                j--;      
            }  
        }  
    }  
    return size;
}
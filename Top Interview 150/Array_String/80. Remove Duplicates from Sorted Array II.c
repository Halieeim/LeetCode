int removeDuplicates(int* nums, int size){
    int counter, i , j , k;
    for ( i = 0; i < size; i ++)  
    {  
        counter = 0;
        for ( j = i + 1; j < size; j++)  
        {  
            // use if statement to check duplicate element  
            if ( nums[i] == nums[j] && ++counter > 1)  
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
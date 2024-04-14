void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j, temp;
    if(n != 0){
        for(i = nums1Size - nums2Size; i < nums1Size; i++){
            nums1[i] = nums2[i-nums1Size+nums2Size];
        }
    }
    if(m == 0){
        for(i = 0; i < nums1Size; i++){
            nums1[i] = nums2[i];
        }
    }
    for(i = 0; i < nums1Size; i++){
        for(j = i; j < nums1Size-1; j++){
            if(nums1[i] > nums1[j+1]){
                temp = nums1[i];
                nums1[i] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }
    }
}
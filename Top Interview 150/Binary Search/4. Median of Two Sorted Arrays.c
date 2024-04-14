int cmp(void* a, void* b){
    return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total_size = nums1Size + nums2Size;
    int* merged_array = (int*)malloc(total_size * sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        merged_array[i] = nums1[i];
    }
    for(int i = nums1Size; i < total_size; i++){
        merged_array[i] = nums2[i-nums1Size];
    }
    qsort(merged_array, total_size, sizeof(int), cmp);
    int median_type = total_size % 2;
    int median_idx = total_size / 2;
    double median = 0.0;
    if(median_type == 1){
        median = merged_array[median_idx];
    }
    else{
        median = (merged_array[median_idx] + merged_array[median_idx-1]) / 2.0;
    }
    return median;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (k >= numsSize) {
        k = k % numsSize;
    }
    
    if (numsSize <= 1 || k == 0) {
        return;
    }
    
    // Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    
    // Reverse the first k elements
    reverse(nums, 0, k - 1);
    
    // Reverse the remaining elements
    reverse(nums, k, numsSize - 1);
}
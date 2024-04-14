int searchInsert(int* nums, int size, int target){
    if(target > nums[size-1]) return size;
    else if(target < nums[0]) return 0;
    
    int left = 0, right = size-1, m = INT_MAX;
    while(left <= right){
        m = left + (right-left)/2;
        if(nums[m] == target) return m;
        else if(nums[m] > target) right = m-1;
        else left = m+1;
    }
    int idx = nums[m] < target ? m+1 : m;
    return m == INT_MAX ? 0 : idx;
}
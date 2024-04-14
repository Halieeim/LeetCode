class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        // Find the pivot index using binary search
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Set the pivot index
        int pivot = left;
        left = 0;
        right = n - 1;
        
        // Decide which subarray to search based on the target value
        if (target >= nums[pivot] && target <= nums[right]) {
            left = pivot;
        } else {
            right = pivot;
        }
        
        // Perform binary search on the selected subarray
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Target not found
        return -1;
    }
};
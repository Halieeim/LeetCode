class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0, right = 0, zeroCount = 0, maxLen = 0;
        
        // Iterate through the array using sliding window
        while (right < nums.length) {
            if (nums[right] == 0) {
                zeroCount++; // Increment zeroCount if the current element is 0
                
                // Shrink the window until zeroCount becomes 1
                while (zeroCount > 1) {
                    if (nums[left] == 0) {
                        zeroCount--;
                    }
                    left++;
                }
            }
            
            // Update maxLen with the length of the current valid subarray
            maxLen = Math.max(maxLen, right - left);
            
            right++; // Increment right pointer to expand the window
        }
        
        // Return maxLen (add 1 because the length is 0-based)
        return maxLen;
    }
}

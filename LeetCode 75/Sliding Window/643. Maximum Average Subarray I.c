double findMaxAverage(int* nums, int numsSize, int k){
    double maxAVG, windowSum = 0.0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    maxAVG = windowSum / k;

    for (int i = k; i < numsSize; i++) {
        windowSum += nums[i] - nums[i - k];
        double avg = windowSum / k;
        if (avg > maxAVG) {
            maxAVG = avg;
        }
    }
    return maxAVG;
}
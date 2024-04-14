int minSubArrayLen(int target, int* nums, int s){
    int sum = 0, min = INT_MAX, counter = 0;
    int *p1 = nums, *p2 = nums;
    for(int i = 0; i < s; i++){
        sum += *p2;
        counter++;
        if(sum >= target){
            min = min <= counter ? min : counter;
            while(sum >= target){
                counter--;
                sum -= *p1;
                p1++;
            }
            min = min <= counter+1 ? min : counter+1;
        }
        p2++;
        // if(min == 1) return min;
    }
    return min == INT_MAX ? 0 : min;
}
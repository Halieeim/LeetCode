int getMax(int* arr, int size){
    int max = INT_MIN;
    for(int i = 0 ; i < size; i++){
        max = max >= arr[i] ? max : arr[i] ;
    }
    return max;
}
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    int max = getMax(candies, candiesSize);
    *returnSize = candiesSize;
    bool* res = (bool*)malloc(candiesSize * sizeof(bool));
    for(int i = 0; i < candiesSize; i++){
        if(candies[i] + extraCandies >= max){
            res[i] = true;
        }
        else
            res[i] = false;
    }
    return res;
}
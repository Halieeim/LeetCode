int candy(int* ratings, int ratingsSize){
    int candies = 0, i;
    int* arr = (int*)malloc(ratingsSize * sizeof(int));
    for(i = 0; i < ratingsSize; i++){
        arr[i] = 1;
    }
    // from left to right
    for(i = 1; i < ratingsSize; i++){
        if(ratings[i] > ratings[i-1])
            arr[i] = arr[i-1] + 1;
    }
    // from right to left
    for(i = ratingsSize-2; i >= 0; i--){
        if(ratings[i] > ratings[i+1] && arr[i] <= arr[i+1])
            arr[i] = arr[i+1] + 1;
    }
    for(i = 0; i < ratingsSize; i++){
        candies += arr[i];
    }
    return candies;
}
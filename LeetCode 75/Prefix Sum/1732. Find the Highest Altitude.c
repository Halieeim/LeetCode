int largestAltitude(int* gain, int size){
    int* arr = (int*)malloc((size+1) * sizeof(int));
    int i, max = INT_MIN;
    arr[0] = 0;
    for(i = 0; i < size; i++){
        arr[i+1] = gain[i] + arr[i];
    }
    for(i = 0; i <= size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
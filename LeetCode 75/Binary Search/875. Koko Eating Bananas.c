int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int minEatingSpeed(int* piles, int size, int h) {
    qsort(piles, size, sizeof(int), cmp);
    if(size == h) return piles[size-1];
    int end = piles[size-1], start = 1;

    if(size == 1){
        return ceil((double)piles[0]/h);
    }

    while(start < end){
        int k = end - (end-start)/2.0;
        int hours = 0;
        // get the needed hours with this k
        for(int j = 0; j < size; j++){
            hours += (piles[j] + k - 1)/k;
        }
        if(hours > h){
            start = k + 1;
        }
        else{
            end = k;
        }
    }

    return start;
}
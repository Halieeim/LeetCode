int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int max(int a, int b){
    return (a>=b)?a:b;
}

int hIndex(int* citations, int citationsSize){
    int ans = 0, i, j, counter = 0;
    qsort(citations, citationsSize, sizeof(int), cmp);
    for(i = citationsSize-1; i >= 0; i--){
        if(citations[i] >= citationsSize-i)
            ans = max(ans, citationsSize-i);
    }
    return ans;
}
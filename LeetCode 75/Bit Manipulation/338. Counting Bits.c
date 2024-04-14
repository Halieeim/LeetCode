/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int *ans = (int*)calloc(n+1, sizeof(int));
    int x, counter;
    for(int i = 0; i <= n; i++){ 
        counter = 0;
        x = 1;
        while(x <= i){
            if(x & i){
                counter++;
            }
            x<<=1;
        }
        ans[i] = counter;
    }
    return ans;
}
int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void treeToArr(struct TreeNode* tree, int* arr, int* idx){
    if(!tree) return;
    arr[(*idx)++] = tree->val;
    treeToArr(tree->left, arr, idx);
    treeToArr(tree->right, arr, idx);
}
int getMinimumDifference(struct TreeNode* root) {
    int i = 0, min = INT_MAX;
    int* arr = (int*)malloc(sizeof(int) * 10000);
    treeToArr(root, arr, &i);
    qsort(arr, i, sizeof(int), cmp);

    for(int j = 0; j < i-1; j++){
        int diff = arr[j+1] - arr[j];
        if(diff < min) min = diff;
    }
    return min;
}
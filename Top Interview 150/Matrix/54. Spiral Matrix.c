int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    (*returnSize) = matrixSize * (*matrixColSize);
    int* spiral = (int*)malloc((*returnSize + 1) * sizeof(int));
    int row_min = 0, row_max = matrixSize, col_min = 0, col_max = (*matrixColSize);
    int idx = 0;
    if(*matrixColSize == 1){
        for(int i = 0; i < *returnSize; i++){
            spiral[idx] = matrix[i][0];
            idx++;
        }
        return spiral;
    }

    while(row_min < row_max && col_min < col_max){
        // ---->
        for(int i = col_min; i < col_max; i++){
            spiral[idx] = matrix[row_min][i];
            idx++;
        }
        row_min++;
        if(row_min >= row_max) break;
        // |
        for(int i = row_min; i < row_max; i++){
            spiral[idx] = matrix[i][col_max-1];
            idx++;
        }
        col_max--;
        if(col_min > col_max) break;
        // <----
        for(int i = col_max-1; i >= col_min; i--){
            spiral[idx] = matrix[row_max-1][i];
            idx++;
        }
        row_max--;
        if(row_min > row_max) break;
        // |^
        for(int i = row_max-1; i >= row_min; i--){
            spiral[idx] = matrix[i][col_min];
            idx++;
        }
        col_min++;
    }
    return spiral;
}
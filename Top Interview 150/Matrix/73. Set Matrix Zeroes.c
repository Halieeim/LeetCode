void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int size = matrixSize * (*matrixColSize), idx = 0;
    if(size == 1) return;
    int** pos = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++){
        pos[i] = (int*)malloc(2 * sizeof(int));
    }
    
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == 0){
                pos[idx][0] = i;
                pos[idx][1] = j;
                idx++;
            }
        }
    }
    pos[idx][0] = -1;
    // substitute
    for(int i = 0; i < size && pos[i][0] >= 0; i++){
        //set zeros in col
        for(int j = 0; j < matrixSize; j++){
            matrix[j][pos[i][1]] = 0;
        }
        //set zeros to row
        for(int j = 0; j < *matrixColSize; j++){
            matrix[pos[i][0]][j] = 0;
        }
    }
}
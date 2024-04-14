void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void transpose(int** matrix, int s){
    for(int i = 0; i < s; i++){
        for(int j = i+1; j < s; j++){
            swap(&(matrix[i][j]), &(matrix[j][i]));
        }
    }
}

void rotate(int** matrix, int s, int* col){
    transpose(matrix, s);
    //Reversing the transpose
    for(int i = 0; i < s; i++){
        for(int j = 0; j < (s/2); j++){
            swap(&(matrix[i][j]), &(matrix[i][s-1-j]));
        }
    }
}
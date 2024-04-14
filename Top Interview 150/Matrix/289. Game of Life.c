void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int size = boardSize * (*boardColSize), counter = 0, row, col, val, idx = 0;
    int** pos = (int**)malloc((size+1) * sizeof(int*));
    for(int i = 0; i < size+1; i++){
        pos[i] = (int*)malloc(2 * sizeof(int));
    }

    //identify elements that will be changed
    for(int i = 0; i < size; i++){
        counter = 0;
        row = i/(*boardColSize);
        col = i%(*boardColSize);
        val = board[row][col];
        for(int j = (row == 0 ? 0 : row-1); j < (row == 0 ? 2 : row+2) && (j < boardSize); j++){
            for(int k = (col == 0 ? 0 : col-1); k < (col == 0 ? 2 : col+2) && (k < *boardColSize); k++){
                if((board[j][k] == 1) && ((j != row) || (k != col))){
                    counter++;
                }
            }
        }
        if((counter == 2 || counter == 3) && val == 1){

        }
        else if((counter < 2 || counter > 3) && val == 1){
            printf("%d %d %d\n", row, col, val);
            pos[idx][0] = row;
            pos[idx][1] = col;
            idx++;
        }
        else if(counter == 3 && val == 0){
            printf("%d %d %d\n", row, col, val);
            pos[idx][0] = row;
            pos[idx][1] = col;
            idx++;
        }
    }
 
    for(int i = 0; (i < size) && pos[i][0] >= 0; i++){
        board[pos[i][0]][pos[i][1]] ^= 1 ;
    }
}
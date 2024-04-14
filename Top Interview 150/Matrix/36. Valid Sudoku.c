bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int* scores = (int*)calloc(10, sizeof(int));
    // check repetition in the rows
    for(int i = 0; i < boardSize; i++){
        // Clearing scores
        memset(scores, 0, 10*sizeof(int));
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] != '.' && scores[board[i][j] - 48] == 1){
                return false;
            }
            else if(board[i][j] != '.') scores[board[i][j] - 48]++;
        }
    }
    // check the columns
    for(int i = 0; i < *boardColSize; i++){
        // Clearing scores
        memset(scores, 0, 10*sizeof(int));
        for(int j = 0; j < boardSize; j++){
            if(board[j][i] != '.' && scores[board[j][i] - 48] == 1){
                return false;
            }
            else if(board[j][i] != '.') scores[board[j][i] - 48]++;
        }
    }

    for(int k = 0; k < boardSize; k += 3){
        for(int m = 0; m < *boardColSize; m += 3){
            // Clearing scores
            memset(scores, 0, 10*sizeof(int));
            // check 3x3 boxes
            for(int i = k; i < k+3; i++){
                for(int j = m; j < m+3; j++){
                    if(board[i][j] != '.' && scores[board[i][j] - 48] == 1){
                        return false;
                    }
                    else if(board[i][j] != '.') scores[board[i][j] - 48]++;
                }
            }
        }
    }
    return true;
}
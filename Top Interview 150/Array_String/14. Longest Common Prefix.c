char result[200] = {0};
char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0, j = 0, flag = 0;
    result[0] = '\0';
    for(j = 0; strs[0][j] != '\0'; j++){
        for(i = 1; i < strsSize; i++){
            if(strs[i][j] == strs[0][j]){
                
            }else{
                flag = 1;
                // break;
            }
        }
        if(flag == 1)
            break;
        else
            result[j] = strs[0][j];
            result[j+1] = '\0';
    }
    return result;
}
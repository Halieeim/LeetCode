char * mergeAlternately(char * word1, char * word2){
    int size = strlen(word1) + strlen(word2) + 1;
    int i, j = 0, k = 0;
    char* res = (char*)malloc(size * sizeof(char));
    memset(res, '\0', size * sizeof(char));
    for(i = 0; i < size; i++){
        if((i % 2 == 0) && (word1[j] != '\0'))
            res[i] = word1[j++];
        else if((i % 2 != 0) && (word2[k] != '\0'))
            res[i] = word2[k++];
        else if(strlen(word1) > strlen(word2))
            res[i] = word1[j++];
        else
            res[i] = word2[k++];
    }
    printf("%s ", res);
    return res;
}
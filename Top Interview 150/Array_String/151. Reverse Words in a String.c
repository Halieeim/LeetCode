char * reverseWords(char * s){
    int size = 0, len = strlen(s);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' ') size++;
    }
    int j = 0;
    char **words = (char**)calloc(size+1, sizeof(char*));
    char *res = (char*)calloc(len*2, sizeof(char));
    char* s_copy = strdup(s);
    const char* delim = " ";
    char* token = strtok(s_copy, delim);
    while(token != NULL){
        words[j] = token;
        j++;
        token = strtok(NULL, delim);
    }
    for(int i = j-1; i >= 0; i--){
        strcat(res, words[i]);
        if(i != 0)
            strcat(res," ");
    }
    return res;
}
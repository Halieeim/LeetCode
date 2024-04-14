bool isSubsequence(char * s, char * t){
    int i, j = 0;
    for(i = 0; t[i] != '\0'; i++){
        if(s[j] != '\0' && s[j] == t[i]){
            j++;
        }
    }
    return j != strlen(s) ? false : true;
}
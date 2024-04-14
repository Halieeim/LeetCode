char* removeStars(char* s) {
    int size = strlen(s), idx = 0;
    char *res = (char*)malloc(size*2 * sizeof(char));
    char *q = s + size - 1;
    char *p = q - 1;
    while(p >= s){
        if(*q == '*' && *p == '*'){
            p--;
        }
        else if(*q == '*' && *p != '*'){
            *p = '0';
            p--;
            q--;
        }
        else if(*q == '0'){
            q--;
        }
        else{
            p--;
            q--;
        }
    }

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != '*' && s[i] != '0'){
            res[idx++] = s[i];
        }
    }
    res[idx] = 0;
    return res;
}
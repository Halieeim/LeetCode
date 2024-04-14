int strStr(char * haystack, char * needle){
    int flag = 0, i , j;
    for(i = 0; haystack[i] != '\0'; i++){
        flag = 0;
        if(haystack[i] == needle[0]){
            for(j = 0; needle[j] != '\0'; j++){
                if(haystack[i+j] != needle[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                flag = 0;
                return i;
            }
        }
    }
    return -1;
}
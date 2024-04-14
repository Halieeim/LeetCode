int cmp(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}
bool isAnagram(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen) return false;
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;
}
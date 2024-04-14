bool isIsomorphic(char * s, char * t){
    int len1 = strlen(s), len2 = strlen(t);
    if(len1 != len2) return false;
    int letters1[128] = {0}, letters2[128] = {0}, i = 0;
    char newT[50001];
    for(i = 0; i < len1; i++){
        if(letters1[s[i]] == 0 && letters2[t[i]] == 0){
            letters1[s[i]] = t[i];
            letters2[t[i]] = s[i];
        }
        else if(letters1[s[i]] == t[i]) continue;
        else return false;
    }
    for(i = 0; i < len1; i++){
        newT[i] = letters1[s[i]];
    }
    newT[i] = '\0';
    if(strcmp(newT, t)) return false;
    return true;
}
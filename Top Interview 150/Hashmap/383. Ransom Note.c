bool canConstruct(char * ransomNote, char * magazine){
    int letters1[128] = {0}, letters2[128] = {0};
    for(int i = 0; magazine[i] != '\0'; i++){
        letters1[magazine[i]] += 1;
    }
    for(int i = 0; ransomNote[i] != '\0'; i++){
        letters2[ransomNote[i]] += 1;
    }
    for(int i = 0; ransomNote[i] != '\0'; i++){
        if(letters1[ransomNote[i]] == 0)
            return false;
        else
            letters1[ransomNote[i]] -= 1;
    }
    return true;
}
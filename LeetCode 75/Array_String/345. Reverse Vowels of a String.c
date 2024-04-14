bool isVowel(char c){    
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    return false;
}

char* reverseVowels(char* s) {
    char *p = s, *q = s + strlen(s) - 1;
    bool c1, c2;
    while(p < q){
        c1 = isVowel(*p);
        c2 = isVowel(*q);
        if(c1 && c2){
            char temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
        else if(c1 && !c2){
            q--;
        }
        else if(!c1 && c2){
            p++;
        }
        else{
            p++;
            q--;
        }
    }
    return s;
}
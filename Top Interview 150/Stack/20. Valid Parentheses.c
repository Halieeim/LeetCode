char getOpposite(char c){
    switch(c){
        case '}':
            return '{';
        case ')':
            return '(';
        case ']':
            return '[';
    }
    return 0;
}
bool isValid(char * s){
    char stack[6000] = {0};
    if(s[0] == 125 || s[0] == 41 || s[0] == 93) return false;
    int len = strlen(s);
    if(len % 2 != 0) return false; /* string length must be even */
    char* p = s;
    int i = 0;
    while(*p != '\0'){
        if(*p != ')' && *p != '}' && *p != ']'){
            stack[i] = *p;
            i++;
        }
        else if(i != 0 && getOpposite(*p) == stack[i-1]){
            stack[i-1] = 0;
            i--; 
        }
        else if(i != 0) return false;
        else if(i == 0 && stack[0] == 0) return false;
        p++;
    }
    return stack[0] ? false : true;
}
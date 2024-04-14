int lengthOfLastWord(char * s){
    int length = 0, i, flag = 0, counter = 0;
    for(i = 0; s[i] != NULL; i++);
    int size = i-1;
    for(i = size; i >= 0; i--){
        if(s[i] != 32){
            flag = 1;
        }
        else if(s[i] == 32){
            if(flag == 1){
                break;
            }
            else{
                counter++;
                continue;
            }
        }
    }
    return size - i - counter;
}
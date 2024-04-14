bool isPalindrome(char * s){
    char *tail = (s+strlen(s)-1);
    char *head = s;
    if(head == tail)
        return true;
    for(int j = 0; s[j] != '\0'; j++){
        do{
            if((*head >= 65 && *head <= 90)){
                *head += 32;
                break;
            }
            else if(*head >= 97 && *head <= 122){
                break;
            }
            else if(*head >= 48 && *head <= 57){
                break;
            }
            else
                head++;
        }while(head < tail);
        
        if(tail == head)
            return true;

        do{
            if((*tail >= 65 && *tail <= 90)){
                *tail += 32;
                break;
            }
            else if(*tail >= 97 && *tail <= 122)
                break;
            else if(*tail >= 48 && *tail <= 57)
                break;
            else 
                tail--;
        }while(tail > head);

        if(tail == head)
            return true;
        else if(*head != *tail)
            return false;
        head++;
        if(tail == head)
            return true;
        tail--;
        if(tail == head)
            return true;
    }
    return true;
}
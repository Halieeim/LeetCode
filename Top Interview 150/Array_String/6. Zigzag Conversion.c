char * convert(char* s, int numRows){
    int len = strlen(s);
    if(numRows == 1 || len <= numRows) return strdup(s);

    char* s_converted = (char*)calloc(len+1, sizeof(char));
    int step = numRows + (numRows-2);
    int counter = 0;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += step) {
            s_converted[counter++] = s[j];
            if (i > 0 && i < numRows - 1 && j + step - 2 * i < len) {
                s_converted[counter++] = s[j + step - 2 * i];
            }
        }
    }
    s_converted[counter] = '\0';
    return s_converted;
}
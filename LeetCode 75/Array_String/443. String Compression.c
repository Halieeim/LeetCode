int compress(char* chars, int charsSize) {
    if (charsSize <= 1) return charsSize; 
    int writeIndex = 0; 
    int count = 1; 
    for (int i = 1; i < charsSize; ++i) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else { 
            chars[writeIndex++] = chars[i - 1]; 

            if (count > 1) {
                int digits = snprintf(NULL, 0, "%d", count); 
                char buffer[digits + 1]; 
                snprintf(buffer, sizeof(buffer), "%d", count); 
                for (int j = 0; j < digits; ++j) {
                    chars[writeIndex++] = buffer[j]; 
                }
                count = 1;
            }
        }
    }
    chars[writeIndex++] = chars[charsSize - 1];
    if (count > 1) {
        int digits = snprintf(NULL, 0, "%d", count);
        char buffer[digits + 1];
        snprintf(buffer, sizeof(buffer), "%d", count);
        for (int j = 0; j < digits; ++j) {
            chars[writeIndex++] = buffer[j];
        }
    }

    return writeIndex; 
}
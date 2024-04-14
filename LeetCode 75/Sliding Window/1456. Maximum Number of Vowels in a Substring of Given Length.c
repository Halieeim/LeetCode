bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

int maxVowels(char* s, int k) {
    int max = 0, counter = 0;
    char *p = s;

    // Count vowels in the first k characters
    for (int i = 0; i < k; ++i) {
        if (isVowel(*(p + i))) {
            counter++;
        }
    }
    max = counter;

    // Slide the window and update max
    p += k;
    for (; *p != '\0'; ++p) {
        if (isVowel(*p)) {
            counter++;
        }
        if (isVowel(*(p - k))) {
            counter--;
        }
        max = (counter > max) ? counter : max;
    }

    return max;
}
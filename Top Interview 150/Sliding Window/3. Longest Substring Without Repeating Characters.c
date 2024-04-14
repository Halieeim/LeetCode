int lengthOfLongestSubstring(char * s){
    char arr[128] = {0};
    int counter = 0, max = 0, p = 0, window = 0, r = 0;
    for(int i = 0; s[i] != '\0'; i++){
        arr[s[i]]++;
        if(arr[s[i]] > 1){
            max = max > counter ? max : counter;
            counter = 0;
            if (window == (i - p) && r < 8){
                r++;
            }
            else window = (i-p);
            if(r >= 8) return max;
            p++;
            memset(arr, 0 , 128 * sizeof(char));
            i = p-1;
        }
        else{
            counter++;
        }
    }
    return max = max > counter ? max : counter;
}
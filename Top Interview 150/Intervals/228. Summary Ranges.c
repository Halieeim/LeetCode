char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    const int n = numsSize;
    char** result = (char**)calloc(n, sizeof(char*));

    int size = 0;
    for (int i = 0; i < n; i++) {
        const int begin = nums[i];
        while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
            i++;
        }
        const int end = nums[i];
        if (begin != end) {
            int len = (begin < 0) + 10 + 2 + (end < 0) + 10 + 1;
            result[size] = (char*)calloc(len, sizeof(char));
            char temp[12]; 
            sprintf(temp, "%d", begin);
            int j = 0;  
            while (temp[j] != '\0') {
                result[size][j++] = temp[j];
            }

            result[size][j++] = '-';
            result[size][j++] = '>';

            char buff[12]; 
            sprintf(buff, "%d", end);
            int k = 0;
            while (buff[k] != '\0') {
                result[size][j++] = buff[k++];
            }
            result[size][j] = '\0';
            size++;
        }
        else {
            int len = (begin < 0) + 10 + 1;
            result[size] = (char*)calloc(len, sizeof(char));

            char temp[12];
            sprintf(temp, "%d", begin);
            int j = 0;  
            while (temp[j] != '\0') {
                result[size][j++] = temp[j];
            }
            result[size][j] = '\0';
            size++;
        }
    }

    *returnSize = size;
    return result;
}
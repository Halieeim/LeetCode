char* addBinary(char* a, char* b) {
    int size1 = strlen(a);
    int size2 = strlen(b);
    int maxSize = size1 > size2 ? size1 : size2;
    char* result = (char*)malloc((maxSize + 2) * sizeof(char)); // +1 for the result and +1 for the null-terminator

    int carry = 0;
    int index1 = size1 - 1;
    int index2 = size2 - 1;
    int resultIndex = 0;

    while (index1 >= 0 || index2 >= 0 || carry) {
        int bit1 = (index1 >= 0) ? a[index1--] - '0' : 0;
        int bit2 = (index2 >= 0) ? b[index2--] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        result[resultIndex++] = (sum % 2) + '0';
    }

    result[resultIndex] = '\0';

    // Reverse the result
    int left = 0;
    int right = resultIndex - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}